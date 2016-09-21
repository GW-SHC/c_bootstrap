# Bootstrapping C - Module 1
## GWU Systems Hacking Club

This module covers the following concepts:
 - Datatypes and variables
 - Control Structures
 - Functions

### Datatypes and Variables Introduction

So far we have:\n
	#include <stdio.h>

	int
	main() {
	    printf("Hello World!\n");
	}
Cool, we can print a nice sentence or *String* of text.\n
But what happens if we don't want to use the string "Hello World"?\n
We would have to go back and hardcode in a new string to print.\n
Furthermore, if we used multiple
	printf
statements we would have to go and change each string to be our new desired text.\n

There must be a better way!!

#### There is a better way...

Variables let us store and use information of some form without having to know
exactly what the value in the variable is.\n
In math this is equivalent to what we do all the time in algebra.\n
We can replace:
	2 + 2 = 4
With:
	x + y = ?
and we can store any value we want in x and y.\n
Before we begin working with variables we need also have a quick introduction to *types*.\n
A variable's type defines what sort of information we are going to be storing in the variable.\n

Lets look at some of the most common examples:\n
char   - stores a single character: 'a', 'b', 'c', '1', '5', or '%', '&'\n
int    - stores a single whole number: 0, 50, -1, 499, 2342351\n
double - stores a single decimal number: 0.1, 0.111, 452.05, 0.0\n

In addition to these basic types there are modifiers that can affect how large of a value the variable can store.\n For example short int, long int and long double are variables that can hold ranges of [-32767, +32767], [−2147483647, +2147483647], and +/- 1.7e +/- 308 (~15 digits) respectively.

### Putting it all together

Lets look at an example of everything we have seen so far in code

	$ cat mod02.c


