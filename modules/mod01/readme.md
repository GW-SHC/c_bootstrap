# Bootstrapping C - Module 1
## GWU Systems Hacking Club

So you survived Module 0. Impressive. But you will never make it through me... __MODULE 1__!

This module covers the following concepts:
 - Comments
 - Datatypes and variables
 - Control Structures
 - Functions

### Comment your code...DO IT

![](https://s-media-cache-ak0.pinimg.com/564x/b1/4e/04/b14e04d971d4a187883989c4d2c15abb.jpg)

Comments, either one lined or in a block, are ignored by the compiler and serve the very important purpose of providing context about your code to other programmers.
Reading code to understand how the software behaves is not an easy task and can take a considerable amount of time. Therefore, to make others lives easier, you should always leave comments where you do something nonintuitive. When in doubt, leave a comment to let the reader know why something is or how it works.
	// a one line comment
	/* Also a one lined comment */
	/*
	 * This is a
	 * comment block
	 */

However, many people starting out tend to leave comments like the following:

```c
// Add one to X
x = x + 1;
```

Resist the urge. The reader of the code can clearly tell what happens in the code by reading the actual source, the comment just wastes space. Comments are important for parts of your code that are not immediately obvious to the reader, but simply cause clutter when they document things that are trivial. In the example above, the following comment would be much more useful:

```c
/**
 * This is a strange edge case in the program. Due to cosmic rays, this variable often gets "magically" decremented.
 * Let's fix that here before we move on. We should probably find the source of said rays...
 */
x = x + 1;
```

![Your IDE's color may vary.](https://imgs.xkcd.com/comics/commented.png)
*https://xkcd.com/156/*

### Datatypes and Variables Introduction

So far we have:

	#include <stdio.h>

	int
	main() {
	    printf("Hello World!\n");
	}
Cool, we can print a nice sentence or __*String*__ of text.
But what happens if we don't want to use the string "Hello World"?
We would have to go back and hardcode in a new string to print.
Furthermore, if we used multiple `printf` statements we would have to go and change each string to be our new desired text.


There must be a better way!!


### There is a better way...

Variables let us store and use information of some form without having to know
exactly what the value in the variable is.
In math this is equivalent to what we do all the time in algebra.
We can replace:

	2 + 2 = 4

With:

	x + y = ?

and we can store any value we want in x and y.
Before we begin working with variables we need also have a quick introduction to __*types*__.
A variable's type defines what sort of information we are going to be storing in the variable.

Lets look at some of the most common examples:

|        |      |
| ------ | ---  |
| char   | stores a single character: 'a', 'b', 'c', '1', '5', or '%', '&' |
| int    | stores a single whole number: 0, 50, -1, 499, 2342351 |
| double | stores a single decimal number: 0.1, 0.111, 452.05, 0.0 |
| String\* | stores a string of characters: "<insert manuscrip of Shrek here>", "a;sldjavmawo;e", "Gabé Parmesan" |

In addition to these basic types there are modifiers that can affect how large of a value the variable can store.
For example `short int`, `long int` and `long double` are variables that can hold ranges of [-32767, +32767], [−2147483647, +2147483647], and +/- 1.7e +/- 308 (~15 digits) respectively.

In C, integer variables (`char`, `int`, and `long`) can be `signed` or `unsigned`. This affects the binary representation of the variable in memory (how the data is actually stored). As the name suggests, `unsigned` variables can only store positive numbers. Additionally, it is possible for a variable to "overflow". Consider teh case where you add one to a variable constantly - once you perform the addition more times than the maximum size of the variable the value will "wrap around" back to the minimum. This is an effect of the way the number is stored in memory.

There are two phases to using variables in a C program - declaration and initialization. Before you use a variable, you must "declare" it to the compiler - you must specify what the type of the variable is and what your name is. Then, after that, you can assign values to and read from the variable. An interesting note about variables: C does not guarantee an uninitialized variable has any default values. The default value is actually whatever was in that memory before you were using it (e.g. garbage). Moral of the story: always initialize your variables. Here is an example:

```c
unsigned long myNumber;
myNumber = 1337;

printf("My number is %dl\n", myNumber);
```

\* In C, there is no explicit `String` type. Instead, the type `char *` is used. This will be explained more in Module 3.

### Control Structures

Control structures make programming interesting. It lets our program decide what it should do given some information.

The two most basic control structures are:
1. `if`
2. `else`

	if (statement is true) {
		/* Do something awesome */
	} else {
		/* Do something less awesome */
	}

If the statement we place in the `if` statement is true we will execute the code block within the {...} brackets otherwise we will execute what is in the `else` {...} block. Think of the `else` block as a catch-all case. The only condiditon we need to execute the `else` block is for the prior `if` to be false.
You can have an `if` statement that is by itself, but you can not have an `else` statement by itself, there must always be an `if` that comes before it. 

**Why do you think this is so?**

#### Loops

Looping is very useful thing to do and can be acomplished in either a `for` or `while` loop.
The following is only an example of the syntax, see the sections below for a code example and don't be affraid to try it out as much as possible yourself!


`For` loops itterate a given n number of times:

	int i;
	for(i = 0 ; i < 10 ; i = 1 + i) {
		/* Do something on every loop */
	}

In this case, n is 10 and we will run as long as i, starting at 0 and increasing by one on every loop, is less than 10.
The initial term `i = 0` is the start value assign to i at the beginning of the loop. This only happens once. The middle term `i < 10` is the value we compare to every time the loop iterates. The last term `i = i + 1` is the value that i is increased by every loop. How many times would the above loop iterate if we did `i = i + 2`? How about `i = i + 3`?

`While` loops itterate while something is true. The equivalent `while` loop:

	int i = 0;
	while(i < 10) {
		/* Do something on every loop */
		i++ /* fancy way of writing i = i + 1 */
	}


### Functions

TODO

### Putting it all together

Lets take a look at everything covered in this module in code

	$ cat mod02.c

TODO
