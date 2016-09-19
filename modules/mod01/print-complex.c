#include <stdio.h>
#include "complex.h"

int
main() {
    struct complex num;

    num.real = 2.5;
    num.imaginary = 3;

    printf("The complex number is %f+%fi\n", num.real, num.imaginary);

}
