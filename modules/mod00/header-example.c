#include <stdio.h>
#include "header.h"

int
main() {
        /**
         * Notice we can use this function **before** it is implemented
         * That is because the function signature is declared in "header.h"
         * and it is implemented below in this file
         */
        doStuff();
}

void
doStuff() {
        printf("The answer to life, the universe, and everything is %d\n", ANSWER_TO_LIFE);
}
