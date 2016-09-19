# Bootstrapping C - Module 0
## GWU Systems Hacking Club

So, you want to learn C? These documents will walk you through getting bootstrapped, with some commentary on how they apply to systems. "Systems" refers to low-level software, like the operating system of your computer. It can also refer to high performance code optimized to do very specific things, like advanced networking.

### Module Outline
 - Getting an environment set up
 - **TODO** Learning the basics of using a UNIX Shell
 - **TODO** Choosing an editor
 - **TODO** Learning git basics
 - Running a HelloWorld program in C
 - Some brief backgound on C source files, header files, and what `#include` means
 - **TODO** Input/Output in C programs (printf, scanf)

### Humble Beginnings
To start off, we need access to a C compiler. We recommend you use a computer running MacOS or Linux. We'll be happy to help you install Linux, if you like. Once you have an operating system, get comfortable with it's terminal (or shell), which you'll use to run programs.

**TODO** Add some links on getting started here (including shell, editor, compiling, and running)

![](http://imgs.xkcd.com/comics/fashion_police_and_grammar_police.png)

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

You can compile and run the program like this. `gcc` is the "GNU C Compiler", which compiles C code into a program your computer can execute. You can name the output executable program with the `-o` option (if it is not specified, the default is `a.out`).
```
$ gcc -o hello-world hello-world.c
$ ./hello-world
Hello World!
```

### Header Files
In a marked difference from Java, C process source files linearly - starting from the top and working its way down. Therefore, you need to define a function before it is used. Often, functions are declared in *Header Files*, which have a `.h` extension. These files contain declarations for functions, constants, and macros (which we'll get to in the next section). [Here](https://www.tutorialspoint.com/cprogramming/c_header_files.htm) is some more information about header files.

### The Preprocessor
Before C programs are compiled, they are run through the *Preprocessor*. This program performs basic modifications to the source. The `#include` directive (which you can see on the first line of `hello-world.c`) basically "copies and pastes" the contents of the referenced file. [Wikipedia](https://en.wikipedia.org/wiki/C_preprocessor) has some good examples of things you can do with the preprocessor.

### Let's Try it Out
Compile and run `header-example.c`:
```
$ gcc -o header-example header-example.c
$ ./header-example
The answer to life, the universe, and everything is 42
```

**Exercise:** Change the value for the `ANSWER_TO_LIFE` constant and see how it affects the output.

### Going from Here
Once you can run the basic program, your environment is all set up and you're ready to start learning! From here, these modules roughly follow the cs1111 (intro to software development in Java) course as outlined [here](https://www.seas.gwu.edu/~simhaweb/cs1111/coursework.html) and the cs1112 course (basic Algorithms and Data Structures) as outlined [here](https://www.seas.gwu.edu/~simhaweb/cs133/coursework.html). Much of the java syntax and program components will not be discussed here, since they'll translate pretty cleanly to C. We'll keep this about the fun stuff :)
