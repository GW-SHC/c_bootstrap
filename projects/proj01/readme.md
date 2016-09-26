# Bootstrapping C - Project 1
## GWU Systems Hacking Club

In this project, you will get comfortable with some [webserver code](https://github.com/GW-SHC/gw-http) and implement a super awesome 404 page (what gets displayed when the server is unable to find the requested page).

![<A>: Like </a>this.&nbsp;](http://imgs.xkcd.com/comics/tags.png)

*http://xkcd.com/1144/*

## Background
How does a webserver work, might you ask. Good news! The code linked above is a nice concice implementation to uses as a reference. It is important to take some time and read the code to get a feeling for how it works. Here are some tips for reading a new codebase:
 - Know where to start. Try and find the `main` function or file and trace through a simple set of execution steps
 - Search the repostiory. `git grep -n` is a command you can use to search for a string in all files in the code repository. The `-n` option will tell the command to print line numbers in the file (in `vim` you can navigate to line X in the current file by running `: X`) in normal mode.
 - Get good at identifying lines for error checking, they are typically at the beginning of a function. Once you identify what lines are error checking, you can typically ignore it, it's probably not critical to the operation of the function. This lets you distill the code you have to understand down to only the core parts.
 - Make a decision about whether you traverse the code "depth first" or "breadth first" or a balance of the two. You don't want to investigate every function you come across, just the "important" ones (which you will have to determine).
 - Understand which function calls are to the kernel (or syscalls). You can reference the manual for these functions by using the `man` function. For example, you can see details about the `read` function by running `man 2 read` (you may need to [install these packages](http://superuser.com/questions/40609/how-to-install-man-pages-for-c-standard-library-functions-in-ubuntu)).

A webserver uses the "socket" APIs available. A "socket" is a connection to the network through the kernel. The server accepts a request from the user over a socket (by default on port 8080), tries to load the file specified into a buffer using `read`, and then writes it back out to the user with `write`. The critical code is the `content_get` function in `content.c`. Understanding how this function works is critical for understanding how requests are served.

## Getting Started
First, make sure you have a GitHub account. Then, read these articles to get a grasp on some of the concepts involved with managing your code using `git`:
 - https://git-scm.com/book/en/v1/Git-Basics
 - https://help.github.com/articles/fork-a-repo/
 - https://help.github.com/articles/about-pull-requests/
 - https://guides.github.com/introduction/flow/
 - https://guides.github.com/activities/hello-world/

Next, you can fork the [webserver repository](https://github.com/GW-SHC/gw-http) into your own namespace, clone the repository, and create a branch for this project, say `project1`.

Now, run the server as outlined in that project's README and see if you can get a page to appear:
```
$ make
$ ./gw-http 8080
...point your browser to localhost:8080/shc.html...
```

Now, try and read through the existing code and understand the following
 - How the application starts
 - Where a request is processed
 - What code finds and returns the specified html file

## The Project
You should do the following
 - Create an awesome html page to show when the server can't find what was requested
 - Modify the server to return that page instead of a constant string
 - You will mainly be modifying the `error_resp` function in `content.c`

## Sharing Your Work
 - Push your code to its own branch in *your fork* of the repository
 - Create a "Pull Request" to the [main repository](https://github.com/GW-SHC/gw-http)
  - This pull request probably won't be merged (so we don't have competing implementations in the main branch), but it allows for you to share exactly what changes you made and provide a nice way for other people to comment on it and to help you improve. In other (real) projects, the goal is to get your changes merged, however
 - Create a markdown file in this repository, under `submission/your-name/proj1` with a link to your other pull request. This is simply for recordkeeping, so you can track all your work in one place.
