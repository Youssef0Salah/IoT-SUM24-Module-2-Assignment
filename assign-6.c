#include <stdio.h>

int main() {
    int num1, factorial = 1;

    printf("Enter an integer: ");
    scanf("%d", &num1);

    for(int i = num1; i >= 1; i--) {
        factorial *= i;
    }

    printf("Factorial of %d is %d\n", num1, factorial);

    return 0;
}
