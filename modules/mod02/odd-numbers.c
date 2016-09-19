#include <stdio.h>

int
main() {
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
}
