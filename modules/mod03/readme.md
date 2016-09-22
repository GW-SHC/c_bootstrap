# Bootstrapping C - Module 3
## GWU Systems Hacking Club

This module covers the following concepts:
 - Pointers
 - Memory Allocation

### Pointers
Pointers are where things start to get tricky. C is an amazingly powerful weapon when it comes to solving complex problems, but it also gives you many ways to shoot yourself in the foot doing so. To understand pointers, we're going to need to understand how variables are actually stored in memory. There are two primary places a variable can be stored: **the stack** or **the heap**. When you declare a variable inside a function, space is allocated for it on the [*call stack*](https://en.wikipedia.org/wiki/Call_stack), within that function's [*stack frame*](http://www.cs.uwm.edu/classes/cs315/Bacon/Lecture/HTML/ch10s07.html). All local variables for the function are stored on the stack, and subsequently go away once the function call completes. We'll talk about the heap in the next section.

Now, we can understand what pointers are. When you have a function with local variables like the one below, enough space to store one `int` and one `double` is included in the stack frame for the function. You can manipulate those variables as long as you want, until the function completes. It is also important to note that each of those variables has a *memory address* where it "lives". An address simply refers to where exactly the data is stored in memory, like how a Post Office Box number refers to a specific location where mail can be stored.

```c
void
someFunction() {
    int foo;
    double bar;
}
```

A *pointer* is simply the address of a variable - it "points" to where you can find the data in memory. Pointers are defined using `*`. So, a variable defined as an `int *` is a *pointer to an integer*. You can use the `&` operator to get the "address of" another variable, and use `*` to *dereference* a pointer, which means "fetch the data pointed to" (yes, star has two different meanings in C. One to define variables as pointers, and one to get the data associated with an existing pointer. Yes, it's confusing).

**Exercise 1:** Compile and run `simple-pointers.c` to get a feel for how pointers work. Then, make modifications to the variables `foo` and `*ptr` (the dereferenced value of `ptr`) and see how it affects the other.

![Every computer, at the unreachable memory address 0x-1, stores a secret. I found it, and it is that all humans ar-- SEGMENTATION FAULT.](https://imgs.xkcd.com/comics/pointers.png)

*https://xkcd.com/138/*

Why is this important? In C, arguments passed to functions are *copied* (the lingo is "passing by value"). So, if you want to pass a variable (or a struct) to another function, have it change the value, and then have those changes persist after the function call, you can't simply pass the entire struct as a parameter.

**Exercise 2:** Why?

Instead, we can pass pointers to other functions. In essence, we're saying: "hey, you know that variable over there? Yeah, modify that one". This lets us make modifications to variables inside other functions and keep their value.

**Exercise 3:** Run `pass-by-reference.c` and explore the concept. Once you're comfortable with the idea, include `complex.h` from module 2 and make another function to add two complex number parameters and store the result in a the third parameter. Here is the function prototype:

```c
void
add_complex(struct *complex num1, struct complex *num2, struct complex *result);
```

Two final concepts surrounding pointers. First, is possible to point to "nowhere". This is done using the value `NULL`. Second, if you have a pointer to a struct, C has some nice syntax to easily dereference it and access a member variable:

```c
struct complex *number;

// This:
(*number).real = 4;

// Is the same as:
number->real = 4;
```

**Exercise 4:** Try setting a pointer value to `NULL` and dereferencing it. What happens?

Let's revisit arrays briefly. Remember that 0 is the first index in an array. This choice makes calculating the address of an item in the array trivial using the address of the first item and the `sizeof` operator.

**Exercise 5:** Write a formula for the address of the `i`th index of an array using `sizeof` and the address of the first element, `base`.

One final note about pointers: it is possible to have a "generic" pointer that doesn't have a type associated with it. These pointer are called *void pointers*, denoted `void *`. This is just a pointer to "anything", it is just a memory location you can store. Void pointers cannot be dereferenced (because the compiler wouldn't know what type to assign the value). However, they are incredibly useful.

For an in-depth discussion about pointers and arrays, read [this document](http://home.earthlink.net/~momotuk/pointers.pdf).

### Allocating Memory
In the previous section, we didn't fully explain what "the heap" was. **The heap** is another region of memory where you can store variables, but these are not tied to the lifecycle of the parent function. Once memory is allocated on the heap, it stays there for the lifetime of your program or you explicitly release it. This is another important aspect of C: in some other languages (such as Java), heap memory is automatically returned once it is no longer referenced (a technique called ["Garbage Collection"](https://en.wikipedia.org/wiki/Garbage_collection_(computer_science)), which was the focus of a [past meeting](https://github.com/GW-SHC/info/wiki/Garbage-Collection-Basics). This is not the case in C, all heap memory used by your program must be explicitly allocated and released.

When you want to request memory from the heap, use the function call [`malloc`](http://man7.org/linux/man-pages/man3/free.3.html), as defined in `stdlib.h`. After you are done with the memory, release it to be allocated again using `free`. The `malloc` function takes a single parameter: the amount of memory you want and returns a pointer to that memory. `free` accepts the pointer you wish to deallocate. Often, you are allocating memory for a struct - an easy way to find out how much memory an item takes up is the `sizeof` function.

```c
#include <stdlib.h>

struct complex *number; // This is a pointer to a complex number struct

number = malloc(sizeof(struct complex); // We are allocating enough memory for the struct

// Do stuff with number

free(number); // Be sure to free when you're done!
```

**Exercise 6:** Make another version of your complex number addition program from module 2, this time allocating memory for the structs on the heap instead of the stack.
