#include <stdio.h>

float calculateAverage(int array[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return (float)sum / size;
}

int main() {
    int size, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter %d integers: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    float average = calculateAverage(array, size);
    printf("The average of the entered numbers is: %.2f\n", average);

    return 0;
}
