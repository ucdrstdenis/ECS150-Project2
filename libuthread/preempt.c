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

/*
 * Frequency of preemption
 * 100Hz is 100 times per second
 */
#define HZ      100
#define ITVAL   1000000 / HZ
#define IT_VIRT ITIMER_VIRTUAL
#define MAGIC_NUMBER  33554432                          /* Value of __val[0] when SIGVTALRM is set */

static const sigset_t alarmMask;
static const struct itimerval disableTimer;

/* **************************************************** */
/*                      Preempt Save                    */
/* **************************************************** */
void preempt_save(sigset_t *level)
{
    printf("Masking Interrupt\n");
    sigprocmask(SIG_BLOCK, &alarmMask, level);          /* Mask the interrupt, level is current->sigset_t */
    getitimer(IT_VIRT, uthread_current()->it);          /* Store the current preemption state             */
    preempt_disable();                                  /* Disable the timer interrupts                   */
}
/* **************************************************** */
/* **************************************************** */
/*                    Preempt Restore                   */
/* **************************************************** */
void preempt_restore(sigset_t *level)
{
    preempt_enable();                                  /* Enable timer preemption                         */
    sigprocmask(SIG_UNBLOCK, &alarmMask, level);       /* Un-mask the interrupt                           */
}
/* **************************************************** */
/* **************************************************** */
/*                    Preempt Enable                    */
/* **************************************************** */
void preempt_enable(void)
{
    if (setitimer(IT_VIRT, uthread_current()->it, NULL)) {
        perror("setitimer");
        exit(1);
    }
}
/* **************************************************** */
/* **************************************************** */
/*                    Preempt Disable                   */
/* **************************************************** */
void preempt_disable(void)
{
    printf("Disabling timer\n");
    if (setitimer(IT_VIRT, &disableTimer, NULL)) {      /* DisableTimer is a static const global            */
        perror("setitimer");
        exit(1);
    }
}
/* **************************************************** */
/* **************************************************** */
/*                  Preempt Disabled                    */
/* **************************************************** */
bool preempt_disabled(void)
{
 //   sigset_t *level = malloc(sizeof(sigset_t));
 //   sigprocmask(SIG_SETMASK, NULL, level);
    //printf("disabled? %lu", level->)  /*unsigned long int/

   // printf("\n\n\n");
   // sigaddset(level, SIGVTALRM);

    //for (i=0; i< _SIGSET_NWORDS; i++)
     //   printf("%lu\n", level->__val[i]);


   sigset_t *sigset = uthread_current()->sigset;
   return (bool) sigismember(sigset, SIGVTALRM);

   //struct itimerval it;
   //getitimer(ITIMER_VIRTUAL, &it);
   // printf("DEBUG: disabled? value = %d", it.it_value.tv_usec);
   // printf("\n\n\n\n");
   // if (it.it_value.tv_usec) return true;
   // else                     return false;
}
/* **************************************************** */
/* **************************************************** */
/*                  Timer Handler                       */
/* **************************************************** */
/*
 * timer_handler - Timer signal handler (aka interrupt handler)
 * @signo - Received signal number (can be ignored)
 */
static void timer_handler(int signo)
{
    printf("DEBUG: timer handler, signal=%d\n", signo);
    uthread_yield();

}
/* **************************************************** */
/* **************************************************** */
/*                     Preempt Start                    */
/* **************************************************** */
void preempt_start(void)
{
	struct sigaction sa;
	struct itimerval it;

	/*
	 * Install signal handler @timer_handler for dealing with alarm signals
	 */

	sa.sa_handler = timer_handler;
	sigemptyset(&sa.sa_mask);                           /* Don't block any signals that are received */

    sigaddset(alarmMask, SIGVTALRM);                    /* Store the alarm mask in a global for re-use */


	/* Make functions such as read() or write() to restart instead of
	 * failing when interrupted */
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGVTALRM, &sa, NULL)) {
		perror("sigaction");
		exit(1);
	}

	/*
	 * Configure timer to fire alarm signals at a certain frequency
	 */
	it.it_value.tv_sec = 0;
	it.it_value.tv_usec = 1000000 / HZ;                 /* 10,000 us - 10 ms */
	it.it_interval.tv_sec = 0;
	it.it_interval.tv_usec = 1000000 / HZ;              /* 10,000 us - 10 ms */
	if (setitimer(ITIMER_VIRTUAL, &it, NULL)) {         /* Timer only decrements while process runs */
		perror("setitimer");
		exit(1);
	}

	/*
	 * Initialize itimerval for fast disabling of timer
	 */
	disableTimer.it_value.tv_sec = 0;
	disableTimer.it_value.tv_usec = 0;
	disableTimer.it_interval.tv_sec = 0;
	disableTimer.it_interval.tv_usec = 0;
}
/* **************************************************** */
