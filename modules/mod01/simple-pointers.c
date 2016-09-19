#include <stdio.h>

int
main () {
   int foo = 42;   /* this is an actual variable on the stack*/
   int *ptr;       /* this is a pointer to an integer */

   ptr = &foo;  /* store address of foo in pointer variable*/

   printf("Address of foo: %x\n", &foo);

   /* address stored in pointer variable */
   printf("Address stored in ptr: %x\n", ptr);

   /* access the value using the pointer */
   printf("Value of *ptr variable: %d\n", *ptr);
}
