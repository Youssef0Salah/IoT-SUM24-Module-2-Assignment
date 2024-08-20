#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            } else {
            arr[k] = R[j];
            j++;
            }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int main() {
    srand(time(NULL));
    int size;
    printf("Enter size of the array: ");
    scanf("%d",&size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i<size;i++) arr[i] = rand()% 101;
    printf("Given array is \n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    mergeSort(arr, 0, size - 1);

    printf("\nSorted array is \n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    if (size % 2 ==0) {
        printf("The median is: %f\n", (float)(arr[(int)size/2] + arr[(int)size/2 + 1])/2);    
    }
    else{
        printf("The median is: %d\n", arr[(size+1)/2]);
}
    free(arr);
    return 0;
}
