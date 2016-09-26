#include <stdio.h>

/* Forward declaration for max
 * This function returns the larger of its two inputs
 */
int max(int num1, int num2);

/* Forward declaration for min
 * This function returns the smaller of its two inputs
 */
int min(int num1, int num2);

int
main() {
    int num1;
    int num2;
    int maxVal;
    int minVal;

    printf("Input an integer: ");
    scanf("%d", &num1);

    printf("Input another integer: ");
    scanf("%d", &num2);

    maxVal = max(num1, num2);
    printf("The larger number is: %d\n", maxVal);

    // Implement the min function
    // minVal = min(num1, num2);
    // printf("The smaller number is: %d\n", minVal);
}

int
max(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}
