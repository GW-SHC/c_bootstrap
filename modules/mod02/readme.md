# Bootstrapping C - Module 2
## GWU Systems Hacking Club

This module covers the following concepts
 - Arrays
 - Structs
 - Unions

### Arrays
You may already be familiar with arrays from another programming language. Good news! It's probably very similar to how arrays work in C. An array can store a fixed-size sequence of variables, all of the same type. Arrays always consist of contiguous memory, allocated in one large block (but split up among the various elements in the array).

![](https://www.tutorialspoint.com/cprogramming/images/arrays.jpg)
[*Image from tutorialspoint.com*](https://www.tutorialspoint.com/cprogramming/c_arrays.htm)

You can define an array using hard brackets containing the number of elements: `array_type variable_name [ size ];`. In C, arrays must always have a constant size (which you must know at compile time for your program). It is also possible to initialize an array using a set of known values.

It is also important to note that array indexes begin with 0 (you access the first item in an array called `numbers` with `numbers[0]`). This is an intentional design choice, and we'll understand why once we get to pointers.

Consider the code snippet below that calculates the first 10 odd numbers (which can be found using the formula `2k + 1`):

```c
// In odd-numbers.c

// Declare and initialize an array of the first 10 integers
int n[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// Declare an array (but it is currently unitialized) to store the odd numbers
int odds[10];
int i;

/* Calculate the first 10 odd numbers */
for (i = 0; i < 10; i++) {
    odds[i] = 2*n[i] + 1;
}

/* Print out the numbers */
for (i = 0; i < 10; i++) {
    printf("The %ith odd number is %d\n", i, odds[i]);
}
```

**Exercise 1**: Create a program that calculates and stores the first 10 fibonacci numbers. Recall that the first two numbers in the sequence are 0 and 1, and that all following items are the sum of the previous two. Define an array that will contains the first 20 items in the sequence, calculate the numbers using a loop, and then print out the values you calculated.

### Structs
Many programming languages have the concept of "objects", or containers for variables that represent a "real thing". C has a similar concept, called the `struct`. A struct is a grouped list of variables, which you can give a type name. A common example is representing a complex number, which contains a real and imaginary part.

```c
struct complex {
    double real;
    double imaginary;
};
```

You can interact with structs just like any other type, and you can interact with its variables using the `.` operator:

```c
int
main() {
    struct complex num;

    num.real = 2.5;
    num.imaginary = 3;

    printf("The complex number is %f+%fi\n", num.real, num.imaginary);
}
```

More information about structs can be found [here](http://www.tutorialspoint.com/cprogramming/c_structures.htm)

**Exercise 2:** Make your own file, `add-complex.c` that uses the `complex.h` header and computes the sum of two complex numbers.

### Unions
Unions are a slightly esoteric concept, although they can be incredibly useful at times. They work very similarly to structs, but with one notible difference. A `union` is a list of variables, *exactly one* of which is defined. For example, you can define a `union` like:

```c
union person_info {
    double gpa;
    int salary;
}
```

And you can access a single member, just like you do with a struct:

```c
union person_info student;
union person_info graduate;

student.gpa = 3.50;
graduate.salary = 100000;

printf("The student's GPA is %f\n", student.gpa);
printf("The professional's salary is %d\n", graduate.salary);
```

In this case, a student will have a GPA but not a salary and professionals will have salaries but not a current GPA. The two variables are mutually exclusive, only one can be set and used.

**Exercise 3:** How much memory will a `union` take up?

