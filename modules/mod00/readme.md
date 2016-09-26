# Bootstrapping C - Module 0
## GWU Systems Hacking Club

So, you want to learn C? These documents will walk you through getting bootstrapped, with some commentary on how they apply to systems. "Systems" refers to low-level software, like the operating system of your computer. It can also refer to high performance code optimized to do very specific things, like advanced networking.

### Module Outline
 - Getting an environment set up
 - Learning the basics of using a UNIX Shell
 - Choosing an editor
 - Learning git basics
 - Running a HelloWorld program in C
 - Some brief backgound on C source files, header files, and what `#include` means
 - Input/Output in C programs (printf, scanf)
 - Makefiles

### Humble Beginnings
To start off, we need access to a C compiler. We recommend you use a computer running MacOS or Linux. We'll be happy to help you install Linux, if you like. Once you have an operating system, get comfortable with it's terminal (or shell), which you'll use to run programs.

**Exercise 1:** Find a computer that has a UNIX-like shell.

### The UNIX Shell
The UNIX shell is a wonderful thing, it lets you manipulate anything on the system and you can do things much faster entirely with the keyboard. Let's hop in our time machine, head back to 1983, and work in simple colors with only a terminal at our disposal. At the shell prompt, you can input commands (invoke text editors, compile and run files, run other programs, etc) to *do stuff*. [This tutorial set](https://www.tutorialspoint.com/unix/unix-getting-started.htm) is something you should skim through and understand some basics on how to interact with a shell.

**Exercise 2**: Run some basic commands in your shell and get comfortable. Make directories, and `cd` around to change your current working directory. Get comfortable with the basics of the filesystem.

### Choosing an Editor
Choosing an editor is a personal, almost religious decision. It will be your most trusty sidekick and your loyal companion through good times and in bad, in sickness and health, and until death do you part. There are many wrong choices, but only on right one. The trouble is, the "right" choice varies heavily depending on who you ask. [Begun, the editor wars have](https://en.wikipedia.org/wiki/Editor_war).

![](http://imgs.xkcd.com/comics/fashion_police_and_grammar_police.png)
> *https://xkcd.com/1735/*

Basically, you should just pick something and stick to it. Your choices include, but aren't limited to:
 - [`vim`](https://scotch.io/tutorials/getting-started-with-vim-an-interactive-guide)
 - [`emacs`](http://www.jesshamrick.com/2012/09/10/absolute-beginners-guide-to-emacs/)
 - [`nano`](http://www.howtogeek.com/howto/42980/the-beginners-guide-to-nano-the-linux-command-line-text-editor/)
 - [`ed`](https://sanctum.geek.nz/arabesque/actually-using-ed/)

![Real programmers set the universal constants at the start such that the universe evolves to contain the disk with the data they want.](https://imgs.xkcd.com/comics/real_programmers.png)
> *https://xkcd.com/378/*

**Exercise 3:** Pick an editor (if you can't decide, use `vim`). Now, make some regular text files, put some stuff in them, and save them. Then, use `cat` to display the modifications you made.

### Basics of git
All of these tutorials are on GitHub, a website that hosts git repositories. As we go through the various projects, you'll learn some basics of working with version controlled code. For now, skim this tutorial on [`git` basic concepts](https://www.tutorialspoint.com/git/git_basic_concepts.htm) and keep the terms in mind. We'll use them later.

![If that doesn't fix it, git.txt contains the phone number of a friend of mine who understands git. Just wait through a few minutes of 'It's really pretty simple, just think of branches as...' and eventually you'll learn the commands that will fix everything.](https://imgs.xkcd.com/comics/git.png)
> If that doesn't fix it, git.txt contains the phone number of a friend of mine who understands git. Just wait through a few minutes of 'It's really pretty simple, just think of branches as...' and eventually you'll learn the commands that will fix everything.
> *http://xkcd.com/1597/*

**Protip:** The SHC mailing list/Slack channel probably contains at least one person who can be that can give you the "it's really pretty simple..." spiel.

**Exercise 4:** [Fork this repository](https://help.github.com/articles/fork-a-repo/) to your own account namespace and [clone that repository](https://help.github.com/articles/cloning-a-repository/) so you can access the sample code on your machine.

### Hello World
Let's run our first C program. The basic C program looks like this (lines that start with `$` means they should be run as commands):
```
$ cat hello-world.c

#include <stdio.h>

int
main() {
    printf("Hello World!\n");
}
```

You can compile and run the program like this. `gcc` is the "GNU C Compiler", which compiles C code into a program your computer can execute. You can name the output executable program with the `-o` option (if it is not specified, the default is `a.out`). When you compile a program, you should also include these extra flags to `gcc`: `-Wall -Wextra`. These flags enable extra compiler warnings - situations in your code that are not necessary *illegal*, but there is likely something you want to look at a second time. C is a [very lenient language](https://en.wikipedia.org/wiki/Duff%27s_device) about what syntax is allowed, which gives the developer great power but also great responsibility to break things. These extra warnings will help you find and fix these kind of situations.

**Exercise 4:** Run the following `gcc` command to compile the example code and then run the result.
```
$ gcc -Wall -Wextra -o hello-world hello-world.c
$ ./hello-world
Hello World!
```

### Header Files
In a marked difference from Java, C process source files linearly - starting from the top and working its way down. Therefore, you need to define a function before it is used. Often, functions are declared in *Header Files*, which have a `.h` extension. These files contain declarations for functions, constants, and macros (which we'll get to in the next section). [Here](https://www.tutorialspoint.com/cprogramming/c_header_files.htm) is some more information about header files.

### The Preprocessor
Before C programs are compiled, they are run through the *Preprocessor*. This program performs basic modifications to the source. The `#include` directive (which you can see on the first line of `hello-world.c`) basically "copies and pastes" the contents of the referenced file. [Wikipedia](https://en.wikipedia.org/wiki/C_preprocessor) has some good examples of things you can do with the preprocessor.

**Exercise 5:** Compile and run `header-example.c`:
```
$ gcc -Wall -Wextra -o header-example header-example.c
$ ./header-example
The answer to life, the universe, and everything is 42
```

**Exercise 6:** Change the value for the `ANSWER_TO_LIFE` constant and see how it affects the output.

### Basic I/O
You saw in the Hello World program above how you can print text to the console using the `printf` function. You'll use that a lot. You can also read data in from the console into a variable (which we'll explain in more detail in Module 1) using `scanf`. Both `printf` and `scanf` use the concept of a "format string". The format string tells the function call the types of the data you're inputting (types will also be explained in Module 1). It may be good to read up on the concepts of format strings here, and come back after Module 1 when you have a greater understanding of types in C.

**Exercise 7:** Compile and run the following program (`input.c`):
```c
#include <stdio.h>
int
main() {
    int num;
    scanf("%d", &num);
    printf("You input the number %d\n", num);
}
```

### Makefiles
There is one more core concept we should cover here: Makefiles. These are files for the `make` program to describe how to compile a program. These are especially useful when the `gcc` command you need to use gets complicated (which does happen with larger projects). If you write a projet contining C code, you should *always* write a Makefile so other people can compile it. Makefiles can get pretty complex, so we'll only cover the simplest ones here. A basic Makefile could look like (always with the filename `Makefile`):

```
$ cat Makefile
all:
    gcc -o output input.c
```

**Exercise 8:** Write a Makefile for one of the example programs in this module.

### Going from Here
Once you can run the basic program, your environment is all set up and you're ready to start learning! From here, these modules roughly follow the cs1111 (intro to software development in Java) course as outlined [here](https://www.seas.gwu.edu/~simhaweb/cs1111/coursework.html) and the cs1112 course (basic Algorithms and Data Structures) as outlined [here](https://www.seas.gwu.edu/~simhaweb/cs133/coursework.html). Much of the java syntax and program components will not be discussed here, since they'll translate pretty cleanly to C. We'll keep this about the fun stuff :)

One more thing: you may find that these things are difficult and esoteric to learn/figure out. You're right - they are! But they are the code tools used by our systems still, so there is value in learning them. Don't hesitate to ask questions on Slack (seriously, ask a ton of questions, it's how you learn).

![](https://imgs.xkcd.com/comics/server_problem.png)
> *https://xkcd.com/1084/*
