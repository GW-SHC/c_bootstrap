# Bootstrapping C - Project 1
## GWU Systems Hacking Club

In this project, you will get comfortable with some [webserver code](https://github.com/GW-SHC/gw-http) and implement a super awesome 404 page (what gets displayed when the server is unable to find the requested page).

![<A>: Like </a>this.&nbsp;](http://imgs.xkcd.com/comics/tags.png)

*http://xkcd.com/1144/*

## Background
**TODO** Things to outline here
 - Basics of networking
 - C socket APIs

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

**TODO** find Gabe's slides for reading large codebases and link them somehow

## The Project
You should do the following
 - Create an awesome html page to show when the server can't find what was requested
 - Modify the server to return that page

## Sharing Your Work
 - Push your code to its own branch in *your fork* of the repository
 - Create a "Pull Request" to the [main repository](https://github.com/GW-SHC/gw-http)
  - This pull request probably won't be merged (so we don't have competing implementations in the main branch), but it allows for you to share exactly what changes you made and provide a nice way for other people to comment on it and to help you improve. In other (real) projects, the goal is to get your changes merged, however
 - Create a markdown file in this repository, under `submission/your-name/proj1` with a link to your other pull request. This is simply for recordkeeping, so you can track all your work in one place.
