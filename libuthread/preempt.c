#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define _UTHREAD_PRIVATE
#include "preempt.h"
#include "uthread.h"

/* **************************************************** */
/*                   Preempt #DEFINES                   */
/* **************************************************** */
#define HZ              100                             /* Frequency of preemption 100Hz             */
#define uSEC            1000000 / HZ                    /* Create fewer instructions for the program */
#define IT_VIRT         ITIMER_VIRTUAL                  /* Only counts while process is running      */
#define MAGIC_NUMBER    0x2000000                       /* sigset_t->__val[0] if SIGVTALRM is masked */

/* **************************************************** */
/*                    Preempt Globals                   */
/* **************************************************** */
static sigset_t alarmMask;                              /* For faster masking of interrupts          */
static struct itimerval disableTimer = {                /* For faster disabling of the timer         */
    .it_value.tv_usec     = 0,                          /* it_values are long ints, 8 Bytes          */
    .it_value.tv_sec      = 0,
    .it_interval.tv_usec  = uSEC,
    .it_interval.tv_sec   = 0
};
static struct itimerval restoreTimer;                   /* Initialized in preempt_start              */
/* **************************************************** */
/*                     Preempt Save                     */
/* **************************************************** */
void preempt_save(sigset_t *level)
{
    struct itimerval it;

    sigprocmask(SIG_BLOCK, &alarmMask, NULL);           /* Mask the interrupt                        */
    sigpending(level);                                  /* Get the pending signals                  */
    level->__val[0] &= MAGIC_NUMBER;                    /* Don't care about the rest of the signals */
    getitimer(IT_VIRT, &it);                            /* Get the remaining time on the clock       */

    /*
     * Below only works because SIGVTALRM is the
     * only signal that we care about.
     * If other signals were of concern, or
     * .tv_usec was much larger than 10000
     * this could go very very wrong.
     */
    sigpending(level);                                  /* Get the pending signals                  */
    level->__val[0] &= MAGIC_NUMBER;                    /* Bitwise AND with the Magic Number        */
    getitimer(IT_VIRT, &it);                            /* Get the remaining time on the clock      */
    level->__val[0] |= it.it_value.tv_usec;             /* Save time left inside current sigset_t   */

    /*
     * Could also skip the OR and just store it
     * inside  __val[1-15]. Not as much fun...
     */
    preempt_disable();                                  /* Disable the timer                        */
}
/* **************************************************** */
/* **************************************************** */
/*                    Preempt Restore                   */
/* **************************************************** */
void preempt_restore(sigset_t *level)
{
    long unsigned int timeLeft;                        /* Remaining tv_usec after extraction        */

    timeLeft = (~MAGIC_NUMBER & level->__val[0]);      /* Bitwise AND with an inverted magic number */
    restoreTimer.it_value.tv_usec = (long int)timeLeft;/* Save in global to pass to preempt enable  */
    level->__val[0] &= MAGIC_NUMBER;                   /* Stop storing the remaining time           */

    preempt_enable();                                  /* Enable preemption, pick up with timeLeft  */
    sigprocmask(SIG_UNBLOCK, &alarmMask, NULL);        /* Un-mask the interrupt                     */
}
/* **************************************************** */
/* **************************************************** */
/*                     Preempt Enable                   */
/* **************************************************** */
void preempt_enable(void)
{
    if (setitimer(IT_VIRT, &restoreTimer, NULL)) {      /* Enable the timer, restores if saved      */
         perror("setitimer");
         exit(1);
    }
    restoreTimer.it_value.tv_usec = uSEC;               /* Protection, in case called directly      */
}
/* **************************************************** */
/* **************************************************** */
/*                   Preempt Disable                    */
/* **************************************************** */
void preempt_disable(void)
{
    if (setitimer(IT_VIRT, &disableTimer, NULL)) {      /* Disable the timer                        */
        perror("setitimer");
        exit(1);
    }
}
/* **************************************************** */
/* **************************************************** */
/*                   Preempt Disabled                   */
/* **************************************************** */
bool preempt_disabled(void)
{
    struct itimerval it;
    getitimer(ITIMER_VIRTUAL, &it);                     /* Get the current timer values             */
    return (bool) (it.it_interval.tv_usec > 0);         /* Return the boolean                       */
}
/* **************************************************** */
/* **************************************************** */
/*                    Timer Handler                     */
/* **************************************************** */
/*
 * timer_handler - Timer signal handler (aka interrupt handler)
 * @signo - Received signal number (can be ignored)
 */
static void timer_handler(int signo)
{
    uthread_yield();                                    /* yield() saves and restores the timer     */
}
/* **************************************************** */
/* **************************************************** */
/*                    Preempt Start                     */
/* **************************************************** */
void preempt_start(void)
{
	struct sigaction sa;
	static struct itimerval it;

	/*
	 * Install signal handler @timer_handler for dealing
	 * with alarm signals.
	 */
	sa.sa_handler = timer_handler;
	sigemptyset(&sa.sa_mask);

	/* Make functions such as read() or write() to restart
	 * instead of failing when interrupted.
	 */
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGVTALRM, &sa, NULL)) {
		perror("sigaction");
		exit(1);
	}

	/*
	 * Configure timer to fire alarm signals
	 * at 100 Hz
	 */
	it.it_value.tv_sec     = 0;
	it.it_value.tv_usec    = uSEC;                      /* 10,000 us - 10 ms                        */
	it.it_interval.tv_sec  = 0;
	it.it_interval.tv_usec = uSEC;                      /* 10,000 us - 10 ms                        */

	/* ************************************************ */
	restoreTimer = it;                                  /* .tv_usec updated in preempt_save         */
	sigaddset(&alarmMask, SIGVTALRM);                   /* Save for fast masking of alarm           */
	/* ************************************************ */

	if (setitimer(IT_VIRT, &it, NULL)) {
		perror("setitimer");
		exit(1);
	}
}
/* **************************************************** */
