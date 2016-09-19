/**
 * This is a basic C header file showing a forward declaration of a function
 */

/**
 * This block means the header is only actually included once.
 * If the macro value "HEADER_H" is not defined, only then will the actually
 * content of the file be compiled
 */
#ifndef HEADER_H
#define HEADER_H

// We can define constants in header files
#define ANSWER_TO_LIFE 42

// Forward declaration of a function used (and implemented) in header-example.c
void doStuff();

#endif
