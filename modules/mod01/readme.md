# Bootstrapping C - Module 1
## GWU Systems Hacking Club

This module covers the following concepts:
 - Datatypes and variables
 - Control Structures
 - Functions

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
char   - stores a single character: 'a', 'b', 'c', '1', '5', or '%', '&'  
int    - stores a single whole number: 0, 50, -1, 499, 2342351  
double - stores a single decimal number: 0.1, 0.111, 452.05, 0.0  

In addition to these basic types there are modifiers that can affect how large of a value the variable can store.  
For example short int, long int and long double are variables that can hold ranges of [-32767, +32767], [−2147483647, +2147483647], and +/- 1.7e +/- 308 (~15 digits) respectively.  

### Variables in use

