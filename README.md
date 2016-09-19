# C Programming bootstrap

Anyone wanting to understand and do systems programming must know C.  You might use other languages, but it is important to understand the lowest-level programming language (aside from assembly).

# Learning
This repository contains a number of tutorials in the `modules` directory. They will walk you through many of the core concepts surrounding C and systems programming. Go through them at your own pace, making sure to do the exercises and projects along the way. Once you are done, you can keep the code in your own fork of this repository, and add them to the main one via a pull request. Put your code in the directory `submission/<your name>`.

# Resources

Feel free to update this with any resources you find.

- See Essential C at http://cslibrary.stanford.edu/.
- See Pointers and Memory, and Lists and trees at http://cslibrary.stanford.edu/.
- Find a copy of ["The C Programming Language"](https://en.wikipedia.org/wiki/The_C_Programming_Language) for an excessively indepth guide on C. The original!
- For an extremely in-depth description of coding style for readability for systems code, see the [`Composite` style guide](https://github.com/gparmer/Composite/blob/master/doc/style_guide/composite_coding_style.pdf?raw=true).  I'd suggest avoiding this till you've had some experience seeing a fair amount of C code.

What resources have you found?  Post them in this repo!

# Projects

- See https://github.com/GW-SHC/gw-http for code implementing a basic web server in C. Some of the assignments will build on this codebase
- See https://github.com/gparmer/c_object_models_instructional for examples of different types of object orientation implemented in C.
- See https://github.com/gparmer/tlr for a simple bitcode implementation in C for a language.  The "Tiny Language Runtime".

TODO: fork these projects into the GW-SHC.

# Practice

- See the `docs/` directory, it contains some supplemental assignments to the core parts. There are two assignments from OS that will be a good set of bootstrap exercises into using C with pointers, memory allocation, and all of the C-specific goodness.  Start with `docs/linked_list_stuff.pdf`, and move on to `docs/queue_stuff.pdf`.
- See clist.h, cvect.h, cringbuf.h and bitmap.h in Composite at https://github.com/gparmer/Composite/tree/master/src/components/include.  These have a set of unit tests at https://github.com/gparmer/Composite/tree/master/src/platform/tests, so you can see their use.
