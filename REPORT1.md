



<!DOCTYPE html>
<html lang="en" class="">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta content="origin-when-cross-origin" name="referrer" />

    <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/frameworks-a44e0bdd1666101af23963e4027cd7a0a1eea1339e0e7422524f2e7f3900e86b.css" integrity="sha256-pE4L3RZmEBryOWPkAnzXoKHuoTOeDnQiUk8ufzkA6Gs=" media="all" rel="stylesheet" />
    <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/github-51951ec5c896c95673bd8af8b6e5ab2265e8f3c9dd80bae367d8ec0b9ce9f9fc.css" integrity="sha256-UZUexciWyVZzvYr4tuWrImXo88ndgLrjZ9jsC5zp+fw=" media="all" rel="stylesheet" />
    
    
    
    

    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta http-equiv="Content-Language" content="en">
    <meta name="viewport" content="width=device-width">
    
    <title>ECS150-Project2/README.md at Liem&#39;s-Branch · ucdrstdenis/ECS150-Project2</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub">
    <link rel="apple-touch-icon" href="/apple-touch-icon.png">
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-57x57.png">
    <link rel="apple-touch-icon" sizes="60x60" href="/apple-touch-icon-60x60.png">
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-72x72.png">
    <link rel="apple-touch-icon" sizes="76x76" href="/apple-touch-icon-76x76.png">
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114x114.png">
    <link rel="apple-touch-icon" sizes="120x120" href="/apple-touch-icon-120x120.png">
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144x144.png">
    <link rel="apple-touch-icon" sizes="152x152" href="/apple-touch-icon-152x152.png">
    <link rel="apple-touch-icon" sizes="180x180" href="/apple-touch-icon-180x180.png">
    <meta property="fb:app_id" content="1401488693436528">

      <meta content="https://avatars1.githubusercontent.com/u/8234564?v=3&amp;s=400" name="twitter:image:src" /><meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="ucdrstdenis/ECS150-Project2" name="twitter:title" /><meta content="ECS150-Project2 - A thread library? Change when the assignment is officially posted." name="twitter:description" />
      <meta content="https://avatars1.githubusercontent.com/u/8234564?v=3&amp;s=400" property="og:image" /><meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="ucdrstdenis/ECS150-Project2" property="og:title" /><meta content="https://github.com/ucdrstdenis/ECS150-Project2" property="og:url" /><meta content="ECS150-Project2 - A thread library? Change when the assignment is officially posted." property="og:description" />
      <meta name="browser-stats-url" content="https://api.github.com/_private/browser/stats">
    <meta name="browser-errors-url" content="https://api.github.com/_private/browser/errors">
    <link rel="assets" href="https://assets-cdn.github.com/">
    <link rel="web-socket" href="wss://live.github.com/_sockets/VjI6MTQ4ODU2Mjc5OjU3ZGI3MmQyODdiMTA0MTU1NzFkMzViZGZkNjY1ZmE3ZTI1N2NkZjM4MjI3ZmIzYzU1ZTg5ZTU0YzEyNzMyM2E=--2ce0df5b69e947e1ef4921da11be9e40c5b81b49">
    <meta name="pjax-timeout" content="1000">
    <link rel="sudo-modal" href="/sessions/sudo_modal">
    <meta name="request-id" content="B29A:5596:1F35846:323F617:589D6670" data-pjax-transient>
    

    <meta name="msapplication-TileImage" content="/windows-tile.png">
    <meta name="msapplication-TileColor" content="#ffffff">
    <meta name="selected-link" value="repo_source" data-pjax-transient>

    <meta name="google-site-verification" content="KT5gs8h0wvaagLKAVWq8bbeNwnZZK1r1XQysX3xurLU">
<meta name="google-site-verification" content="ZzhVyEFwb7w3e0-uOTltm8Jsck2F5StVihD0exw2fsA">
    <meta name="google-analytics" content="UA-3769691-2">

<meta content="collector.githubapp.com" name="octolytics-host" /><meta content="github" name="octolytics-app-id" /><meta content="https://collector.githubapp.com/github-external/browser_event" name="octolytics-event-url" /><meta content="B29A:5596:1F35846:323F617:589D6670" name="octolytics-dimension-request_id" /><meta content="8234564" name="octolytics-actor-id" /><meta content="ucdrstdenis" name="octolytics-actor-login" /><meta content="cc09878546479d5d984eddba9aeab119321592d2804f4f4bda6cab267b27763e" name="octolytics-actor-hash" />
<meta content="/&lt;user-name&gt;/&lt;repo-name&gt;/blob/show" data-pjax-transient="true" name="analytics-location" />



  <meta class="js-ga-set" name="dimension1" content="Logged In">



        <meta name="hostname" content="github.com">
    <meta name="user-login" content="ucdrstdenis">

        <meta name="expected-hostname" content="github.com">
      <meta name="js-proxy-site-detection-payload" content="MjA1N2E2MDAxMDQ5NTQwYjA5MmUwZDE1NzI2YjM2MGE2MTEzMWNkNzc3NTdhMzVkMjRkNjRkYmVmM2U1NTlmYXx7InJlbW90ZV9hZGRyZXNzIjoiMTY5LjIzNy4zMi43OSIsInJlcXVlc3RfaWQiOiJCMjlBOjU1OTY6MUYzNTg0NjozMjNGNjE3OjU4OUQ2NjcwIiwidGltZXN0YW1wIjoxNDg2NzEwMzg0LCJob3N0IjoiZ2l0aHViLmNvbSJ9">


      <link rel="mask-icon" href="https://assets-cdn.github.com/pinned-octocat.svg" color="#000000">
      <link rel="icon" type="image/x-icon" href="https://assets-cdn.github.com/favicon.ico">

    <meta name="html-safe-nonce" content="d7b8f023a74e7eef77b9ddaad9abfc120ff33854">

    <meta http-equiv="x-pjax-version" content="1f4fb74d9795382043ea19601a4d7517">
    

      
  <meta name="description" content="ECS150-Project2 - A thread library? Change when the assignment is officially posted.">
  <meta name="go-import" content="github.com/ucdrstdenis/ECS150-Project2 git https://github.com/ucdrstdenis/ECS150-Project2.git">

  <meta content="8234564" name="octolytics-dimension-user_id" /><meta content="ucdrstdenis" name="octolytics-dimension-user_login" /><meta content="80381032" name="octolytics-dimension-repository_id" /><meta content="ucdrstdenis/ECS150-Project2" name="octolytics-dimension-repository_nwo" /><meta content="false" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="80381032" name="octolytics-dimension-repository_network_root_id" /><meta content="ucdrstdenis/ECS150-Project2" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/ucdrstdenis/ECS150-Project2/commits/Liem&#39;s-Branch.atom?token=AH2mRCzU2PjBYTbbTirwnRxkEtlzB5ogks62qUdwwA%3D%3D" rel="alternate" title="Recent Commits to ECS150-Project2:Liem&#39;s-Branch" type="application/atom+xml">


      <link rel="canonical" href="https://github.com/ucdrstdenis/ECS150-Project2/blob/Liem&#39;s-Branch/README.md" data-pjax-transient>
  </head>


  <body class="logged-in  env-production linux vis-private page-blob">
    <div id="js-pjax-loader-bar" class="pjax-loader-bar"><div class="progress"></div></div>
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>

    
    
    



        <div class="header header-logged-in true" role="banner">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/" data-hotkey="g d" aria-label="Homepage" data-ga-click="Header, go to dashboard, icon:logo">
  <svg aria-hidden="true" class="octicon octicon-mark-github" height="28" version="1.1" viewBox="0 0 16 16" width="28"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0 0 16 8c0-4.42-3.58-8-8-8z"/></svg>
</a>


        <div class="header-search scoped-search site-scoped-search js-site-search" role="search">
  <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/ucdrstdenis/ECS150-Project2/search" class="js-site-search-form" data-scoped-search-url="/ucdrstdenis/ECS150-Project2/search" data-unscoped-search-url="/search" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div>
    <label class="form-control header-search-wrapper js-chromeless-input-container">
      <div class="header-search-scope">This repository</div>
      <input type="text"
        class="form-control header-search-input js-site-search-focus js-site-search-field is-clearable"
        data-hotkey="s"
        name="q"
        placeholder="Search"
        aria-label="Search this repository"
        data-unscoped-placeholder="Search GitHub"
        data-scoped-placeholder="Search"
        autocapitalize="off">
    </label>
</form></div>


      <ul class="header-nav float-left" role="navigation">
        <li class="header-nav-item">
          <a href="/pulls" aria-label="Pull requests you created" class="js-selected-navigation-item header-nav-link" data-ga-click="Header, click, Nav menu - item:pulls context:user" data-hotkey="g p" data-selected-links="/pulls /pulls/assigned /pulls/mentioned /pulls">
            Pull requests
</a>        </li>
        <li class="header-nav-item">
          <a href="/issues" aria-label="Issues you created" class="js-selected-navigation-item header-nav-link" data-ga-click="Header, click, Nav menu - item:issues context:user" data-hotkey="g i" data-selected-links="/issues /issues/assigned /issues/mentioned /issues">
            Issues
</a>        </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="https://gist.github.com/" data-ga-click="Header, go to gist, text:gist">Gist</a>
          </li>
      </ul>

    
<ul class="header-nav user-nav float-right" id="user-links">
  <li class="header-nav-item">
    
    <a href="/notifications" aria-label="You have no unread notifications" class="header-nav-link notification-indicator tooltipped tooltipped-s js-socket-channel js-notification-indicator" data-channel="tenant:1:notification-changed:8234564" data-ga-click="Header, go to notifications, icon:read" data-hotkey="g n">
        <span class="mail-status "></span>
        <svg aria-hidden="true" class="octicon octicon-bell" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M14 12v1H0v-1l.73-.58c.77-.77.81-2.55 1.19-4.42C2.69 3.23 6 2 6 2c0-.55.45-1 1-1s1 .45 1 1c0 0 3.39 1.23 4.16 5 .38 1.88.42 3.66 1.19 4.42l.66.58H14zm-7 4c1.11 0 2-.89 2-2H5c0 1.11.89 2 2 2z"/></svg>
</a>
  </li>

  <li class="header-nav-item dropdown js-menu-container">
    <a class="header-nav-link tooltipped tooltipped-s js-menu-target" href="/new"
       aria-label="Create new…"
       data-ga-click="Header, create new, icon:add">
      <svg aria-hidden="true" class="octicon octicon-plus float-left" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 9H7v5H5V9H0V7h5V2h2v5h5z"/></svg>
      <span class="dropdown-caret"></span>
    </a>

    <div class="dropdown-menu-content js-menu-content">
      <ul class="dropdown-menu dropdown-menu-sw">
        
<a class="dropdown-item" href="/new" data-ga-click="Header, create new repository">
  New repository
</a>

  <a class="dropdown-item" href="/new/import" data-ga-click="Header, import a repository">
    Import repository
  </a>

<a class="dropdown-item" href="https://gist.github.com/" data-ga-click="Header, create new gist">
  New gist
</a>

  <a class="dropdown-item" href="/organizations/new" data-ga-click="Header, create new organization">
    New organization
  </a>



  <div class="dropdown-divider"></div>
  <div class="dropdown-header">
    <span title="ucdrstdenis/ECS150-Project2">This repository</span>
  </div>
    <a class="dropdown-item" href="/ucdrstdenis/ECS150-Project2/issues/new" data-ga-click="Header, create new issue">
      New issue
    </a>
    <a class="dropdown-item" href="/ucdrstdenis/ECS150-Project2/settings/collaboration" data-ga-click="Header, create new collaborator">
      New collaborator
    </a>

      </ul>
    </div>
  </li>

  <li class="header-nav-item dropdown js-menu-container">
    <a class="header-nav-link name tooltipped tooltipped-sw js-menu-target" href="/ucdrstdenis"
       aria-label="View profile and more"
       data-ga-click="Header, show menu, icon:avatar">
      <img alt="@ucdrstdenis" class="avatar" height="20" src="https://avatars1.githubusercontent.com/u/8234564?v=3&amp;s=40" width="20" />
      <span class="dropdown-caret"></span>
    </a>

    <div class="dropdown-menu-content js-menu-content">
      <div class="dropdown-menu dropdown-menu-sw">
        <div class="dropdown-header header-nav-current-user css-truncate">
          Signed in as <strong class="css-truncate-target">ucdrstdenis</strong>
        </div>

        <div class="dropdown-divider"></div>

        <a class="dropdown-item" href="/ucdrstdenis" data-ga-click="Header, go to profile, text:your profile">
          Your profile
        </a>
        <a class="dropdown-item" href="/ucdrstdenis?tab=stars" data-ga-click="Header, go to starred repos, text:your stars">
          Your stars
        </a>
        <a class="dropdown-item" href="/explore" data-ga-click="Header, go to explore, text:explore">
          Explore
        </a>
          <a class="dropdown-item" href="/integrations" data-ga-click="Header, go to integrations, text:integrations">
            Integrations
          </a>
        <a class="dropdown-item" href="https://help.github.com" data-ga-click="Header, go to help, text:help">
          Help
        </a>

        <div class="dropdown-divider"></div>

        <a class="dropdown-item" href="/settings/profile" data-ga-click="Header, go to settings, icon:settings">
          Settings
        </a>

        <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/logout" class="logout-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="sS7IdBoRNCWnonmKTWCVvnxW3/9R353SvyTUBNV4EpP1CZPwS7nyrf4ivqJcQuBYZXXMdHvvJYrqyy2VnsDhsw==" /></div>
          <button type="submit" class="dropdown-item dropdown-signout" data-ga-click="Header, sign out, icon:logout">
            Sign out
          </button>
</form>      </div>
    </div>
  </li>
</ul>


    
  </div>
</div>


      


    <div id="start-of-content" class="accessibility-aid"></div>

      <div id="js-flash-container">
</div>


    <div role="main">
        <div itemscope itemtype="http://schema.org/SoftwareSourceCode">
    <div id="js-repo-pjax-container" data-pjax-container>
      
<div class="pagehead repohead instapaper_ignore readability-menu experiment-repo-nav">
  <div class="container repohead-details-container">

    

<ul class="pagehead-actions">

  <li>
        <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/notifications/subscribe" class="js-social-container" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="ceZRuKSTdvUEzCW4XACL0HycnsNebe4rnCEbf4qdjD2dhjt8+3QYEK5LWenoENgCX8UKTNEnke7E+9bubWK5KQ==" /></div>      <input class="form-control" id="repository_id" name="repository_id" type="hidden" value="80381032" />

        <div class="select-menu js-menu-container js-select-menu">
          <a href="/ucdrstdenis/ECS150-Project2/subscription"
            class="btn btn-sm btn-with-count select-menu-button js-menu-target" role="button" tabindex="0" aria-haspopup="true"
            data-ga-click="Repository, click Watch settings, action:blob#show">
            <span class="js-select-button">
              <svg aria-hidden="true" class="octicon octicon-eye" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"/></svg>
              Unwatch
            </span>
          </a>
          <a class="social-count js-social-count"
            href="/ucdrstdenis/ECS150-Project2/watchers"
            aria-label="2 users are watching this repository">
            2
          </a>

        <div class="select-menu-modal-holder">
          <div class="select-menu-modal subscription-menu-modal js-menu-content" aria-hidden="true">
            <div class="select-menu-header js-navigation-enable" tabindex="-1">
              <svg aria-label="Close" class="octicon octicon-x js-menu-close" height="16" role="img" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
              <span class="select-menu-title">Notifications</span>
            </div>

              <div class="select-menu-list js-navigation-container" role="menu">

                <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
                  <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
                  <div class="select-menu-item-text">
                    <input id="do_included" name="do" type="radio" value="included" />
                    <span class="select-menu-item-heading">Not watching</span>
                    <span class="description">Be notified when participating or @mentioned.</span>
                    <span class="js-select-button-text hidden-select-button-text">
                      <svg aria-hidden="true" class="octicon octicon-eye" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"/></svg>
                      Watch
                    </span>
                  </div>
                </div>

                <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
                  <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
                  <div class="select-menu-item-text">
                    <input checked="checked" id="do_subscribed" name="do" type="radio" value="subscribed" />
                    <span class="select-menu-item-heading">Watching</span>
                    <span class="description">Be notified of all conversations.</span>
                    <span class="js-select-button-text hidden-select-button-text">
                      <svg aria-hidden="true" class="octicon octicon-eye" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"/></svg>
                      Unwatch
                    </span>
                  </div>
                </div>

                <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
                  <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
                  <div class="select-menu-item-text">
                    <input id="do_ignore" name="do" type="radio" value="ignore" />
                    <span class="select-menu-item-heading">Ignoring</span>
                    <span class="description">Never be notified.</span>
                    <span class="js-select-button-text hidden-select-button-text">
                      <svg aria-hidden="true" class="octicon octicon-mute" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8 2.81v10.38c0 .67-.81 1-1.28.53L3 10H1c-.55 0-1-.45-1-1V7c0-.55.45-1 1-1h2l3.72-3.72C7.19 1.81 8 2.14 8 2.81zm7.53 3.22l-1.06-1.06-1.97 1.97-1.97-1.97-1.06 1.06L11.44 8 9.47 9.97l1.06 1.06 1.97-1.97 1.97 1.97 1.06-1.06L13.56 8l1.97-1.97z"/></svg>
                      Stop ignoring
                    </span>
                  </div>
                </div>

              </div>

            </div>
          </div>
        </div>
</form>
  </li>

  <li>
      <div class="js-toggler-container js-social-container starring-container ">
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/ucdrstdenis/ECS150-Project2/unstar" class="starred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="2LMHNtziIpJSocUnLRVgo9pD+vX27p1qkFhbFqHjXNTBSvOipIHdMWvFPl16Bd9EX2BJkHSC0Fal+2TFBTte3Q==" /></div>
      <button
        type="submit"
        class="btn btn-sm btn-with-count js-toggler-target"
        aria-label="Unstar this repository" title="Unstar ucdrstdenis/ECS150-Project2"
        data-ga-click="Repository, click unstar button, action:blob#show; text:Unstar">
        <svg aria-hidden="true" class="octicon octicon-star" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74z"/></svg>
        Unstar
      </button>
        <a class="social-count js-social-count" href="/ucdrstdenis/ECS150-Project2/stargazers"
           aria-label="0 users starred this repository">
          0
        </a>
</form>
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/ucdrstdenis/ECS150-Project2/star" class="unstarred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="eLMjoC61hdAKQR9NKDaZxLM3SUXuhWoiNcZfQEMuNkHcFHi4PsNIC3ChMICNm5fbKJXuSrUj5XxRVqyTZN7x3Q==" /></div>
      <button
        type="submit"
        class="btn btn-sm btn-with-count js-toggler-target"
        aria-label="Star this repository" title="Star ucdrstdenis/ECS150-Project2"
        data-ga-click="Repository, click star button, action:blob#show; text:Star">
        <svg aria-hidden="true" class="octicon octicon-star" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74z"/></svg>
        Star
      </button>
        <a class="social-count js-social-count" href="/ucdrstdenis/ECS150-Project2/stargazers"
           aria-label="0 users starred this repository">
          0
        </a>
</form>  </div>

  </li>

  <li>
          <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/ucdrstdenis/ECS150-Project2/fork" class="btn-with-count" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="N6g0UbfIORLxNcws3rWTazXLQgbpiZskn0XltA8qGf/sj6yKtnzXzVtktOQgRCyc7OjyVHER9JgXFadJO0dlkA==" /></div>
            <button
                type="submit"
                class="btn btn-sm btn-with-count"
                data-ga-click="Repository, show fork modal, action:blob#show; text:Fork"
                title="Fork your own copy of ucdrstdenis/ECS150-Project2 to your account"
                aria-label="Fork your own copy of ucdrstdenis/ECS150-Project2 to your account">
              <svg aria-hidden="true" class="octicon octicon-repo-forked" height="16" version="1.1" viewBox="0 0 10 16" width="10"><path fill-rule="evenodd" d="M8 1a1.993 1.993 0 0 0-1 3.72V6L5 8 3 6V4.72A1.993 1.993 0 0 0 2 1a1.993 1.993 0 0 0-1 3.72V6.5l3 3v1.78A1.993 1.993 0 0 0 5 15a1.993 1.993 0 0 0 1-3.72V9.5l3-3V4.72A1.993 1.993 0 0 0 8 1zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3 10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3-10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"/></svg>
              Fork
            </button>
</form>
    <a href="/ucdrstdenis/ECS150-Project2/network" class="social-count"
       aria-label="1 user forked this repository">
      1
    </a>
  </li>
</ul>

    <h1 class="private ">
  <svg aria-hidden="true" class="octicon octicon-lock" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M4 13H3v-1h1v1zm8-6v7c0 .55-.45 1-1 1H1c-.55 0-1-.45-1-1V7c0-.55.45-1 1-1h1V4c0-2.2 1.8-4 4-4s4 1.8 4 4v2h1c.55 0 1 .45 1 1zM3.8 6h4.41V4c0-1.22-.98-2.2-2.2-2.2-1.22 0-2.2.98-2.2 2.2v2H3.8zM11 7H2v7h9V7zM4 8H3v1h1V8zm0 2H3v1h1v-1z"/></svg>
  <span class="author" itemprop="author"><a href="/ucdrstdenis" class="url fn" rel="author">ucdrstdenis</a></span><!--
--><span class="path-divider">/</span><!--
--><strong itemprop="name"><a href="/ucdrstdenis/ECS150-Project2" data-pjax="#js-repo-pjax-container">ECS150-Project2</a></strong>
    <span class="label label-private v-align-middle">Private</span>

</h1>

  </div>
  <div class="container">
    
<nav class="reponav js-repo-nav js-sidenav-container-pjax"
     itemscope
     itemtype="http://schema.org/BreadcrumbList"
     role="navigation"
     data-pjax="#js-repo-pjax-container">

  <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
    <a href="/ucdrstdenis/ECS150-Project2/tree/Liem&#39;s-Branch" class="js-selected-navigation-item selected reponav-item" data-hotkey="g c" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches /ucdrstdenis/ECS150-Project2/tree/Liem&#39;s-Branch" itemprop="url">
      <svg aria-hidden="true" class="octicon octicon-code" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M9.5 3L8 4.5 11.5 8 8 11.5 9.5 13 14 8 9.5 3zm-5 0L0 8l4.5 5L6 11.5 2.5 8 6 4.5 4.5 3z"/></svg>
      <span itemprop="name">Code</span>
      <meta itemprop="position" content="1">
</a>  </span>

    <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
      <a href="/ucdrstdenis/ECS150-Project2/issues" class="js-selected-navigation-item reponav-item" data-hotkey="g i" data-selected-links="repo_issues repo_labels repo_milestones /ucdrstdenis/ECS150-Project2/issues" itemprop="url">
        <svg aria-hidden="true" class="octicon octicon-issue-opened" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M7 2.3c3.14 0 5.7 2.56 5.7 5.7s-2.56 5.7-5.7 5.7A5.71 5.71 0 0 1 1.3 8c0-3.14 2.56-5.7 5.7-5.7zM7 1C3.14 1 0 4.14 0 8s3.14 7 7 7 7-3.14 7-7-3.14-7-7-7zm1 3H6v5h2V4zm0 6H6v2h2v-2z"/></svg>
        <span itemprop="name">Issues</span>
        <span class="counter">0</span>
        <meta itemprop="position" content="2">
</a>    </span>

  <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
    <a href="/ucdrstdenis/ECS150-Project2/pulls" class="js-selected-navigation-item reponav-item" data-hotkey="g p" data-selected-links="repo_pulls /ucdrstdenis/ECS150-Project2/pulls" itemprop="url">
      <svg aria-hidden="true" class="octicon octicon-git-pull-request" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M11 11.28V5c-.03-.78-.34-1.47-.94-2.06C9.46 2.35 8.78 2.03 8 2H7V0L4 3l3 3V4h1c.27.02.48.11.69.31.21.2.3.42.31.69v6.28A1.993 1.993 0 0 0 10 15a1.993 1.993 0 0 0 1-3.72zm-1 2.92c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zM4 3c0-1.11-.89-2-2-2a1.993 1.993 0 0 0-1 3.72v6.56A1.993 1.993 0 0 0 2 15a1.993 1.993 0 0 0 1-3.72V4.72c.59-.34 1-.98 1-1.72zm-.8 10c0 .66-.55 1.2-1.2 1.2-.65 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"/></svg>
      <span itemprop="name">Pull requests</span>
      <span class="counter">0</span>
      <meta itemprop="position" content="3">
</a>  </span>

  <a href="/ucdrstdenis/ECS150-Project2/projects" class="js-selected-navigation-item reponav-item" data-selected-links="repo_projects new_repo_project repo_project /ucdrstdenis/ECS150-Project2/projects">
    <svg aria-hidden="true" class="octicon octicon-project" height="16" version="1.1" viewBox="0 0 15 16" width="15"><path fill-rule="evenodd" d="M10 12h3V2h-3v10zm-4-2h3V2H6v8zm-4 4h3V2H2v12zm-1 1h13V1H1v14zM14 0H1a1 1 0 0 0-1 1v14a1 1 0 0 0 1 1h13a1 1 0 0 0 1-1V1a1 1 0 0 0-1-1z"/></svg>
    Projects
    <span class="counter">0</span>
</a>
    <a href="/ucdrstdenis/ECS150-Project2/wiki" class="js-selected-navigation-item reponav-item" data-hotkey="g w" data-selected-links="repo_wiki /ucdrstdenis/ECS150-Project2/wiki">
      <svg aria-hidden="true" class="octicon octicon-book" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M3 5h4v1H3V5zm0 3h4V7H3v1zm0 2h4V9H3v1zm11-5h-4v1h4V5zm0 2h-4v1h4V7zm0 2h-4v1h4V9zm2-6v9c0 .55-.45 1-1 1H9.5l-1 1-1-1H2c-.55 0-1-.45-1-1V3c0-.55.45-1 1-1h5.5l1 1 1-1H15c.55 0 1 .45 1 1zm-8 .5L7.5 3H2v9h6V3.5zm7-.5H9.5l-.5.5V12h6V3z"/></svg>
      Wiki
</a>

  <a href="/ucdrstdenis/ECS150-Project2/pulse" class="js-selected-navigation-item reponav-item" data-selected-links="pulse /ucdrstdenis/ECS150-Project2/pulse">
    <svg aria-hidden="true" class="octicon octicon-pulse" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M11.5 8L8.8 5.4 6.6 8.5 5.5 1.6 2.38 8H0v2h3.6l.9-1.8.9 5.4L9 8.5l1.6 1.5H14V8z"/></svg>
    Pulse
</a>
  <a href="/ucdrstdenis/ECS150-Project2/graphs" class="js-selected-navigation-item reponav-item" data-selected-links="repo_graphs repo_contributors /ucdrstdenis/ECS150-Project2/graphs">
    <svg aria-hidden="true" class="octicon octicon-graph" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M16 14v1H0V0h1v14h15zM5 13H3V8h2v5zm4 0H7V3h2v10zm4 0h-2V6h2v7z"/></svg>
    Graphs
</a>
    <a href="/ucdrstdenis/ECS150-Project2/settings" class="js-selected-navigation-item reponav-item" data-selected-links="repo_settings repo_branch_settings hooks integration_installations /ucdrstdenis/ECS150-Project2/settings">
      <svg aria-hidden="true" class="octicon octicon-gear" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M14 8.77v-1.6l-1.94-.64-.45-1.09.88-1.84-1.13-1.13-1.81.91-1.09-.45-.69-1.92h-1.6l-.63 1.94-1.11.45-1.84-.88-1.13 1.13.91 1.81-.45 1.09L0 7.23v1.59l1.94.64.45 1.09-.88 1.84 1.13 1.13 1.81-.91 1.09.45.69 1.92h1.59l.63-1.94 1.11-.45 1.84.88 1.13-1.13-.92-1.81.47-1.09L14 8.75v.02zM7 11c-1.66 0-3-1.34-3-3s1.34-3 3-3 3 1.34 3 3-1.34 3-3 3z"/></svg>
      Settings
</a>
</nav>

  </div>
</div>

<div class="container new-discussion-timeline experiment-repo-nav">
  <div class="repository-content">

    

<a href="/ucdrstdenis/ECS150-Project2/blob/3d223a0fe763aec33cd53f0083838813ee568c65/README.md" class="d-none js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:73e00b83e25af755230da8b97533c5b4 -->

<div class="file-navigation js-zeroclipboard-container">
  
<div class="select-menu branch-select-menu js-menu-container js-select-menu float-left">
  <button class="btn btn-sm select-menu-button js-menu-target css-truncate" data-hotkey="w"
    
    type="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <i>Branch:</i>
    <span class="js-select-button css-truncate-target">Liem&#39;s-Branch</span>
  </button>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <svg aria-label="Close" class="octicon octicon-x js-menu-close" height="16" role="img" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
        <span class="select-menu-title">Switch branches/tags</span>
      </div>

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Find or create a branch…" id="context-commitish-filter-field" class="form-control js-filterable-field js-navigation-enable" placeholder="Find or create a branch…">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" data-filter-placeholder="Find or create a branch…" class="js-select-menu-tab" role="tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" data-filter-placeholder="Find a tag…" class="js-select-menu-tab" role="tab">Tags</a>
            </li>
          </ul>
        </div>
      </div>

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches" role="menu">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <a class="select-menu-item js-navigation-item js-navigation-open selected"
               href="/ucdrstdenis/ECS150-Project2/blob/Liem&#39;s-Branch/README.md"
               data-name="Liem&#39;s-Branch"
               data-skip-pjax="true"
               rel="nofollow">
              <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
              <span class="select-menu-item-text css-truncate-target js-select-menu-filter-text">
                Liem&#39;s-Branch
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/ucdrstdenis/ECS150-Project2/blob/Rob&#39;s-Branch/README.md"
               data-name="Rob&#39;s-Branch"
               data-skip-pjax="true"
               rel="nofollow">
              <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
              <span class="select-menu-item-text css-truncate-target js-select-menu-filter-text">
                Rob&#39;s-Branch
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/ucdrstdenis/ECS150-Project2/blob/master/README.md"
               data-name="master"
               data-skip-pjax="true"
               rel="nofollow">
              <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
              <span class="select-menu-item-text css-truncate-target js-select-menu-filter-text">
                master
              </span>
            </a>
        </div>

          <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/ucdrstdenis/ECS150-Project2/branches" class="js-create-branch select-menu-item select-menu-new-item-form js-navigation-item js-new-item-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="T4U4CSvWypawndun7uusunx2jCD0bbM0sQuGPPrrf8tC/8ePDv2OPjPmLt+XaQeU2E7A93BZ4SkvBVu/lKCSpg==" /></div>
          <svg aria-hidden="true" class="octicon octicon-git-branch select-menu-item-icon" height="16" version="1.1" viewBox="0 0 10 16" width="10"><path fill-rule="evenodd" d="M10 5c0-1.11-.89-2-2-2a1.993 1.993 0 0 0-1 3.72v.3c-.02.52-.23.98-.63 1.38-.4.4-.86.61-1.38.63-.83.02-1.48.16-2 .45V4.72a1.993 1.993 0 0 0-1-3.72C.88 1 0 1.89 0 3a2 2 0 0 0 1 1.72v6.56c-.59.35-1 .99-1 1.72 0 1.11.89 2 2 2 1.11 0 2-.89 2-2 0-.53-.2-1-.53-1.36.09-.06.48-.41.59-.47.25-.11.56-.17.94-.17 1.05-.05 1.95-.45 2.75-1.25S8.95 7.77 9 6.73h-.02C9.59 6.37 10 5.73 10 5zM2 1.8c.66 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2C1.35 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2zm0 12.41c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm6-8c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"/></svg>
            <div class="select-menu-item-text">
              <span class="select-menu-item-heading">Create branch: <span class="js-new-item-name"></span></span>
              <span class="description">from ‘Liem&#39;s-Branch’</span>
            </div>
            <input type="hidden" name="name" id="name" class="js-new-item-value">
            <input type="hidden" name="branch" id="branch" value="Liem&#39;s-Branch">
            <input type="hidden" name="path" id="path" value="README.md">
</form>
      </div>

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div>

    </div>
  </div>
</div>

  <div class="BtnGroup float-right">
    <a href="/ucdrstdenis/ECS150-Project2/find/Liem&#39;s-Branch"
          class="js-pjax-capture-input btn btn-sm BtnGroup-item"
          data-pjax
          data-hotkey="t">
      Find file
    </a>
    <button aria-label="Copy file path to clipboard" class="js-zeroclipboard btn btn-sm BtnGroup-item tooltipped tooltipped-s" data-copied-hint="Copied!" type="button">Copy path</button>
  </div>
  <div class="breadcrumb js-zeroclipboard-target">
    <span class="repo-root js-repo-root"><span class="js-path-segment"><a href="/ucdrstdenis/ECS150-Project2/tree/Liem&#39;s-Branch"><span>ECS150-Project2</span></a></span></span><span class="separator">/</span><strong class="final-path">README.md</strong>
  </div>
</div>


  <div class="commit-tease">
      <span class="float-right">
        <a class="commit-tease-sha" href="/ucdrstdenis/ECS150-Project2/commit/3d223a0fe763aec33cd53f0083838813ee568c65" data-pjax>
          3d223a0
        </a>
        <relative-time datetime="2017-02-10T02:55:22Z">Feb 9, 2017</relative-time>
      </span>
      <div>
        <img alt="@liemnguyen15" class="avatar" height="20" src="https://avatars3.githubusercontent.com/u/25287737?v=3&amp;s=40" width="20" />
        <a href="/liemnguyen15" class="user-mention" rel="contributor">liemnguyen15</a>
          <a href="/ucdrstdenis/ECS150-Project2/commit/3d223a0fe763aec33cd53f0083838813ee568c65" class="message" data-pjax="true" title="Update README.md">Update README.md</a>
      </div>

    <div class="commit-tease-contributors">
      <button type="button" class="btn-link muted-link contributors-toggle" data-facebox="#blob_contributors_box">
        <strong>2</strong>
         contributors
      </button>
          <a class="avatar-link tooltipped tooltipped-s" aria-label="liemnguyen15" href="/ucdrstdenis/ECS150-Project2/commits/Liem&#39;s-Branch/README.md?author=liemnguyen15"><img alt="@liemnguyen15" class="avatar" height="20" src="https://avatars3.githubusercontent.com/u/25287737?v=3&amp;s=40" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="ucdrstdenis" href="/ucdrstdenis/ECS150-Project2/commits/Liem&#39;s-Branch/README.md?author=ucdrstdenis"><img alt="@ucdrstdenis" class="avatar" height="20" src="https://avatars1.githubusercontent.com/u/8234564?v=3&amp;s=40" width="20" /> </a>


    </div>

    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header" data-facebox-id="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list" data-facebox-id="facebox-description">
          <li class="facebox-user-list-item">
            <img alt="@liemnguyen15" height="24" src="https://avatars1.githubusercontent.com/u/25287737?v=3&amp;s=48" width="24" />
            <a href="/liemnguyen15">liemnguyen15</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@ucdrstdenis" height="24" src="https://avatars3.githubusercontent.com/u/8234564?v=3&amp;s=48" width="24" />
            <a href="/ucdrstdenis">ucdrstdenis</a>
          </li>
      </ul>
    </div>
  </div>


<div class="file">
  <div class="file-header">
  <div class="file-actions">

    <div class="BtnGroup">
      <a href="/ucdrstdenis/ECS150-Project2/raw/Liem&#39;s-Branch/README.md" class="btn btn-sm BtnGroup-item" id="raw-url">Raw</a>
        <a href="/ucdrstdenis/ECS150-Project2/blame/Liem&#39;s-Branch/README.md" class="btn btn-sm js-update-url-with-hash BtnGroup-item" data-hotkey="b">Blame</a>
      <a href="/ucdrstdenis/ECS150-Project2/commits/Liem&#39;s-Branch/README.md" class="btn btn-sm BtnGroup-item" rel="nofollow">History</a>
    </div>


        <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/ucdrstdenis/ECS150-Project2/edit/Liem&#39;s-Branch/README.md" class="inline-form js-update-url-with-hash" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="L9mjqs6wkW6LZAxyhblgnt9tO9jRuPNsZWRy6mcbDi8IN95MBQvU6fCrdh5/vBwncV58K/MiAzTEKL/eRMlRTg==" /></div>
          <button class="btn-octicon tooltipped tooltipped-nw" type="submit"
            aria-label="Edit this file" data-hotkey="e" data-disable-with>
            <svg aria-hidden="true" class="octicon octicon-pencil" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M0 12v3h3l8-8-3-3-8 8zm3 2H1v-2h1v1h1v1zm10.3-9.3L12 6 9 3l1.3-1.3a.996.996 0 0 1 1.41 0l1.59 1.59c.39.39.39 1.02 0 1.41z"/></svg>
          </button>
</form>        <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/ucdrstdenis/ECS150-Project2/delete/Liem&#39;s-Branch/README.md" class="inline-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="WwqlULobuLdEVT6788E0FmOvoPTdpzPLOvDcBytNpTWZ1oUrZFZ9+Hr/d4dbGa0VDf+SXrAEThsChS6AulvpWg==" /></div>
          <button class="btn-octicon btn-octicon-danger tooltipped tooltipped-nw" type="submit"
            aria-label="Delete this file" data-disable-with>
            <svg aria-hidden="true" class="octicon octicon-trashcan" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M11 2H9c0-.55-.45-1-1-1H5c-.55 0-1 .45-1 1H2c-.55 0-1 .45-1 1v1c0 .55.45 1 1 1v9c0 .55.45 1 1 1h7c.55 0 1-.45 1-1V5c.55 0 1-.45 1-1V3c0-.55-.45-1-1-1zm-1 12H3V5h1v8h1V5h1v8h1V5h1v8h1V5h1v9zm1-10H2V3h9v1z"/></svg>
          </button>
</form>  </div>

  <div class="file-info">
      84 lines (42 sloc)
      <span class="file-info-divider"></span>
    14.9 KB
  </div>
</div>

  
  <div id="readme" class="readme blob instapaper_body">
    <article class="markdown-body entry-content" itemprop="text"><p>% ECS 150: Project #2 - User-level thread library</p>

<h1><a id="user-content-general-information" class="anchor" href="#general-information" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>General information</h1>

<p>We approached each phase individually, from the beginning stages of phase 1, to the final stages of phase 4.</p>

<h2><a id="user-content-phase-1---creating-new-execution-threads" class="anchor" href="#phase-1---creating-new-execution-threads" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Phase 1 - Creating new execution threads.</h2>

<p>We first implemented a FIFO queue, by making modifications in queue.c. We defined the node and queue structures, then defined the functions queue_create, queue_destroy, queue_enqueue, queue_dequeue, queue_delete, queue_iterate, and queue_length. Our implementations all had to be in O(1) constant time, so we chose to use if statements and while loops and NOT for loops.</p>

<p>For queue_create, we first allocated memory space for a queue we locally initialize. If we failed to allocate proper memory space for our initialization, we would return NULL for the function call. If we succeded to allocate proper memory space for our initialization, then we set the queue head to NULL, tail to NULL, and length to 0. Then we return the initialized queue.</p>

<p>For queue_destroy, we pass a queue structure as a parameter into our function. If the queue is NULL, we return a failure. If the head of the queue is not NULL, we return a failure. If the tail of the queue is not NULL, we return a failure. If the length of the queue is not NULL, we return a failure. Essentially we don't want to destroy a queue that is not empty. If none of these failures are reached, then we simply free the queue, and return a success.</p>

<p>For queue_enqueue, we need to push a node onto the queue. We pass a queue structure and data pointer as parameters into our function. We first allocated memory space for a node we locally initialize. If we failed to allocate proper memory space for our initialization, we would return a failure. If the queue we passed in as a parameter was NULL, we would also return a failure. If a queue is not empty, but the head of the queue is NULL, we set the head of the queue to be our locally initialized node. If the head of the queue is not NULL, then we set the tail of the queue to be our locally initialized node, by simply pointing the current tail to the node. We make the final adjustments by initializing our node's data, attaching our node to the head of the queue, pointing the queue's tail to our node, and increasing the length of our queue. </p>

<p>For queue_dequeue, we need to remove a node from the queue. We pass a queue structure and data double pointer as parameters into our function. If the queue is NULL, queue's head is NULL, or the queue's tail is NULL, we return a failure. If not, then we set the data double pointer we passed in to equal to the data of the queue's head, by deferencing. Then, if we fail to remove the node from the queue by the queue_delete() function call, then we return a failure. If we succeed to remove the node from the queue, then we return a success.</p>

<p>For queue_delete, we pass a queue structure and data pointer as parameters into our function. We first initialized two node pointers, a current node we intend to use, and a temporary node we'll also need. If the queue or queue's head is NULL, we return a failure. Else, we set our initialized current node to equal the queue's head, so we can start to iterate over the queue. If there are more items in the queue, and the current node's data is the data of the node we want to delete, then we set the temporary node as the next node after the current node, so that we can overrite by setting the data and next values of the current node to equal the data and next values of the following (temporary node). Once that's done, we need to free the temporary node to be safe, since we no longer need its allocation of memory. If the node we overrited (deleted) was the tail of the queue, we set the current node as our new queue's tail, and decrement the length of the queue, since one node has been deleted from there. Then we can return a success. However, if the current node's data is not the data of the node we want to delete, we simply iterate through the queue until we find the node we need to delete. If the node we need to delete happens to be the queue's tail, we must check the following: if the the tail is the head, there's only one item in the queue, so we can just nullify the entire queue (basically emptying it). If the tail isn't the head, we use our temporary node we initialized in the beginning to be our new tail. We decrement the length of the queue, since one node has been deleted from there, and finally return a success.</p>

<p>For queue_iterate, we pass a queue structure and queue function as parameters into our function. We first initialized two node pointers, a current node we intend to use, and a temporary node we'll also need. If the function or queue is NULL, then we return a failure, because there's nothing to iterate over. If the queue's head is NULL, there is also nothing to iterate, but we return a success since there exists a queue. We set our initialized current node to equal the queue's head, so we can start to iterate over the queue. As we iterate through the queue, we set the temporary node as the next node after the current node. Then we call the function "func" for the current node in the queue. If the function call was successful, we can continue to iterate through the queue. Once we reach the queue's tail, we perform one last function call to the node. The queue_iterate function essentially allows us to execute function "func" calls against every node or element in the queue.</p>

<p>For queue_length, we simply pass a queue structure as the parameter into our function, in order to return the length of our queue. If the queue's head is NULL, we can determine that the length of the queue is 0.</p>

<p>Lastly, we completed the makefile of our libuthread so we can successfully generate a library archive, and we had to add other C files as we started implementing them from one phase to the next phase. We also built a test-queue.c that allows us to test our queue implementations in order.</p>

<h2><a id="user-content-phase-2---schedule-the-execution-of-threads-in-a-round-robin-fashion" class="anchor" href="#phase-2---schedule-the-execution-of-threads-in-a-round-robin-fashion" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Phase 2 - Schedule the execution of threads in a round-robin fashion</h2>

<p>We needed to implement most of the thread management in this phase of the program, which was done by making modifications in uthread.c file. We predefined 4 global pointers to the 4 queues (ready, run, wait, done) to represent the states of a thread during its lifetime. We also defined the set of registers for each state in order to save the thread for descheduling and later scheduling. We also clearly defined the thread control block (TCB) of a typical thread, including in its structure: the thread's state, a pointer to the thread function, a user-level thread context (for context switching), a signal set (for phase 4), and two pointers, one to the thread function's argument and one to the top of the thread function's stack. Lastly, we defined the functions uthread_enqueue, uthread_yield, uthread_init, uthread_create, uthread_exit, uthread_block, uthread_unblock, uthread_current, and uthread_start.</p>

<p>For uthread_enqueue, we pass a pointer to the thread control block (TCB) and the current state of the thread as parameters of the program. By setting the current state of the TCB to equal the state we passed in to the function, we could implement a switch statement to determine which thread state queue to place our TCB in.</p>

<p>For uthread_yield, we declare TCB pointers (next, run, done), each of which represent the state of the thread we'll be dealing with in the function. We also save the signal state and disable interrupts. If we can't remove the next thread from the ready state queue, then we remove the running thread from the run state queue, change state, then add the running thread to the ready state queue and add the next thread to the running state queue. Then we must do a thread context switch for threads that are running and ready, by suspending execution of a currently running thread and resuming execution of another thread. This is needed whenever we deal with multiple threads. From here, while there are finished threads that exist on the done state queue, we destroy their respective stacks and free all of their thread contexts, signal set object, and memory space, simply because we don't need them anymore.</p>

<p>For uthread_init, we pass a thread function and argument of that function as parameters to the function. We must allocate the right amount of memory for the TCB, as well as allocate thread context and signal set object. Then we assign the TCB's function pointer and argument pointer to the parameters we passed in, and set the TCB's current state to ready.</p>

<p>For uthread_create, we make a function call to uthread_init defined earlier to initialize the thread we intend to create. That comes with allocating memory for a stack and pointer to the top of the stack. Once we create our thread, we add it to the ready state queue.</p>

<p>For uthread_exit, we declare TCB pointers (me, next), each of which represent the state of the thread we'll be dealing with in the function. We also save the signal state and disable interrupts. We remove the running thread from the run state queue and remove the next thread from the ready state queue. Then we can change state and add the running and next threads to the done state queue and running state queue, respectively. Then we make the necessary thread context switch. There is no need to restore signal state and re-enable interrupts since we're exiting the thread life cycle.</p>

<p>For uthread_block, we declare TCB pointers (next, run), each of which represent the state of the thread we'll be dealing with in the function. We also save the signal state and disable interrupts. We perform similar actions in this function as we do in uthread_exit. We remove the running thread from the run state queue and remove the next queue from the ready state queue. Then we change state and add the running and next threads from the WAITING state queue and running state queue, respectively. We add the running thread to the waiting state queue so that the thread can next transition to the running state queue. Then we make the necessary thread context switch. Lastly, we restore the signal state and re-enable the interrupts.</p>

<p>For uthread_unblock, we pass a thread as a parameter to the function. We also save the signal state and disable interrupts. We remove the blocked thread from the waiting state queue by calling queue_delete(), and then add that same thread onto the ready state queue. We then restore the signal state and re-enable the interrupts.</p>

<p>For uthread_current, we initialize a local thread structure (current). This function allows us to take hold of the current thread we are dealing with, and we call this function so that it returns us the current thread.</p>

<p>For uthread_start, we pass a thread start function and the argument of that function as parameters to the function. We must iterate through each of the 4 thread states (ready, run, wait, done), in order to see where to initialize our thread. Once we set the state of our thread and add it to the running state queue, we start the timer (<em>Phase 4</em>) and create the thread that we must add to the next queue, the ready state queue.  If a thread already exists, we can simply switch to the next thread by calling uthread_yield(). Lastly, we must conduct memory cleanup in order to assure no memory leak once we no longer need a thread.</p>

<p>Test 1 and 2 confirmed that our function definitions were implemented properly and effectively.</p>

<h2><a id="user-content-phase-3---provide-a-thread-synchronization-api-namely-semaphores" class="anchor" href="#phase-3---provide-a-thread-synchronization-api-namely-semaphores" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Phase 3 - Provide a thread synchronization API, namely semaphores</h2>

<p>In this phase we needed to implement semaphores, which would allow us(ers) to control access to the common resources by multiple threads. </p>

<p>First we needed to properly define a semaphore structure, which contains the "count", the number of threads able to share a common resource at the same time, and waiting state queue, queue of threads waiting to use that resource. We defined the functions sem_create, sem_destroy, sem_down, and sem_up.</p>

<p>For sem_create, we passed the count as the parameter of the function. We must first allocate memory for our semaphore structure, and then create the waiting state queue of waiting threads, and initializing the count of the semaphore we just created.</p>

<p>For sem_destroy, we passed the semaphore structure as the parameter of the function. If we fail to destory the waiting state queue associated with the semaphore, we return a failure. If we succeed to destroy the waiting state queue, then we free its memory and return a success.</p>

<p>For sem_down, threads can ask to grab a resource, so we passed a semaphore structure as the parameter of the function. If the thread tries to grab a resource when the count is down to 0, it adds that thread to the list of threads in the waiting state queue. The thread is put in a blocked state and isn't eligible to scheduling.</p>

<p>For sem_up, threads can release a resource, so we passed a semaphore structure as the parameter of the function. If the thread releases a semaphore which count is 0, it needs to check whether threads exist on the waiting state queue. If so, the first thread of the waiting state queue can be unblocked and ran.</p>

<p>Test 3, 4, and 5 confirmed that our function definitions were implemented properly and effectively.</p>

<h2><a id="user-content-phase-4---be-preemptive-that-is-to-provide-an-interrupt-based-scheduler" class="anchor" href="#phase-4---be-preemptive-that-is-to-provide-an-interrupt-based-scheduler" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Phase 4 - Be preemptive, that is to provide an interrupt-based scheduler</h2>

<p>In this final phase we needed to add a preemption to our user-thread library, by making modifications primarily in preempt.c, but also in other .c files under the libuthread sub-directory. We first needed to predefine the structure for the timer disabler. The functions we defined in preempt.c are preempt_save, preempt_restore, preempt_enable, preempt_disable, preempt_disabled, and timer_handler.</p>

<p>For preempt_save, we pass the "level" signal set as the parameter of the function. We first call sigprocmask(), which allows us mask the interrupt and block the signal call. Then we get the remaining time on the clock by calling getitimer(). We set the amount of time we have left to 0x2000000 and save the time left inside the current signal set we passed in as a parameter. Then we disable the timer, which successfully completes our call to preempt_save to save the time left inside the current signal set "level". </p>

<p>For preempt_restore, we pass the "level" signal set as the parameter of the function. We essentially need to restore the amount of time that is left after extraction, by enabling preemption to pause the ongoing storage of remaining time. Once we enable, we can un-mask the interrupt and restore the time left inside the current signal set "level".</p>

<p>For preempt_enable, if we succesfully enable the timer value of restoreTimer and restore the time if it has been saved, then the function call has done its job.</p>

<p>For preempt_disable, if we successfully disable the timer value of disableTimer, then the function call has done its job.</p>

<p>For preempt_disabled, we simply check if the preemption is currently disabled.</p>

<p>For timer_handler, we can force the currently running thread to yield in order for another thread to be scheduled instead by calling uthread_yield().</p>

<p>If the outputs for test 1-5 are the same while running preempt.c with our modifications, then we know our function implementations were successful, which they were.</p>
</article>
  </div>

</div>

<button type="button" data-facebox="#jump-to-line" data-facebox-class="linejump" data-hotkey="l" class="d-none">Jump to Line</button>
<div id="jump-to-line" style="display:none">
  <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="" class="js-jump-to-line-form" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div>
    <input class="form-control linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" aria-label="Jump to line" autofocus>
    <button type="submit" class="btn">Go</button>
</form></div>

  </div>
  <div class="modal-backdrop js-touch-events"></div>
</div>


    </div>
  </div>

    </div>

        <div class="container site-footer-container">
  <div class="site-footer" role="contentinfo">
    <ul class="site-footer-links float-right">
        <li><a href="https://github.com/contact" data-ga-click="Footer, go to contact, text:contact">Contact GitHub</a></li>
      <li><a href="https://developer.github.com" data-ga-click="Footer, go to api, text:api">API</a></li>
      <li><a href="https://training.github.com" data-ga-click="Footer, go to training, text:training">Training</a></li>
      <li><a href="https://shop.github.com" data-ga-click="Footer, go to shop, text:shop">Shop</a></li>
        <li><a href="https://github.com/blog" data-ga-click="Footer, go to blog, text:blog">Blog</a></li>
        <li><a href="https://github.com/about" data-ga-click="Footer, go to about, text:about">About</a></li>

    </ul>

    <a href="https://github.com" aria-label="Homepage" class="site-footer-mark" title="GitHub">
      <svg aria-hidden="true" class="octicon octicon-mark-github" height="24" version="1.1" viewBox="0 0 16 16" width="24"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0 0 16 8c0-4.42-3.58-8-8-8z"/></svg>
</a>
    <ul class="site-footer-links">
      <li>&copy; 2017 <span title="0.12439s from github-fe140-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="https://github.com/site/terms" data-ga-click="Footer, go to terms, text:terms">Terms</a></li>
        <li><a href="https://github.com/site/privacy" data-ga-click="Footer, go to privacy, text:privacy">Privacy</a></li>
        <li><a href="https://github.com/security" data-ga-click="Footer, go to security, text:security">Security</a></li>
        <li><a href="https://status.github.com/" data-ga-click="Footer, go to status, text:status">Status</a></li>
        <li><a href="https://help.github.com" data-ga-click="Footer, go to help, text:help">Help</a></li>
    </ul>
  </div>
</div>



    

    <div id="ajax-error-message" class="ajax-error-message flash flash-error">
      <svg aria-hidden="true" class="octicon octicon-alert" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.865 1.52c-.18-.31-.51-.5-.87-.5s-.69.19-.87.5L.275 13.5c-.18.31-.18.69 0 1 .19.31.52.5.87.5h13.7c.36 0 .69-.19.86-.5.17-.31.18-.69.01-1L8.865 1.52zM8.995 13h-2v-2h2v2zm0-3h-2V6h2v4z"/></svg>
      <button type="button" class="flash-close js-flash-close js-ajax-error-dismiss" aria-label="Dismiss error">
        <svg aria-hidden="true" class="octicon octicon-x" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
      </button>
      You can't perform that action at this time.
    </div>


      
      <script crossorigin="anonymous" integrity="sha256-yLYY7zvjJ3PYRp69aU73ReRebHprA0Yf/QWYDUYl26Y=" src="https://assets-cdn.github.com/assets/frameworks-c8b618ef3be32773d8469ebd694ef745e45e6c7a6b03461ffd05980d4625dba6.js"></script>
      <script async="async" crossorigin="anonymous" integrity="sha256-BR4owXvw16EbtYt7RcUEGYdB4GgVse5vCSRkcMS5Ofk=" src="https://assets-cdn.github.com/assets/github-051e28c17bf0d7a11bb58b7b45c504198741e06815b1ee6f09246470c4b939f9.js"></script>
      
      
      
      
    <div class="js-stale-session-flash stale-session-flash flash flash-warn flash-banner d-none">
      <svg aria-hidden="true" class="octicon octicon-alert" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.865 1.52c-.18-.31-.51-.5-.87-.5s-.69.19-.87.5L.275 13.5c-.18.31-.18.69 0 1 .19.31.52.5.87.5h13.7c.36 0 .69-.19.86-.5.17-.31.18-.69.01-1L8.865 1.52zM8.995 13h-2v-2h2v2zm0-3h-2V6h2v4z"/></svg>
      <span class="signed-in-tab-flash">You signed in with another tab or window. <a href="">Reload</a> to refresh your session.</span>
      <span class="signed-out-tab-flash">You signed out in another tab or window. <a href="">Reload</a> to refresh your session.</span>
    </div>
    <div class="facebox" id="facebox" style="display:none;">
  <div class="facebox-popup">
    <div class="facebox-content" role="dialog" aria-labelledby="facebox-header" aria-describedby="facebox-description">
    </div>
    <button type="button" class="facebox-close js-facebox-close" aria-label="Close modal">
      <svg aria-hidden="true" class="octicon octicon-x" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
    </button>
  </div>
</div>

  </body>
</html>

