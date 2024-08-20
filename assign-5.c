#include <stdio.h>

int main() {
    int size, i,sum;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter %d integers: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    for(int i = 0; i < size; i++) {
        sum+=array[i];

    }

    printf("The sum is %d ",sum);

    return 0;
}
