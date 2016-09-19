# Bootstrapping C - Module 2
## GWU Systems Hacking Club

This module covers the following concepts
 - **TODO** Arrays
 - Structs
 - **TODO** Unions

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

**Exercise 1:** Make your own file, `add-complex.c` that uses the `complex.h` header and computes the sum of two complex numbers.
