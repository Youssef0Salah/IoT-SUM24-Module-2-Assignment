#include <stdio.h>
#include <stdlib.h>
int *create_array(int size){
	int *arr = (int*) malloc(size*sizeof(int));
	for (int i= 0; i<size;i++){
		arr[i] = (i+1)*5;
	} 

	return arr;
}

void main(){
	int *arr = create_array(5);
	int sum = 0;
	for (int i=0; i<5;i++){
		printf("Current element: %d\n",arr[i]);
		sum += arr[i];
		printf("Cumulative sum: %d\n",sum);
	}
	printf("The sum is %d\n",sum);


}
