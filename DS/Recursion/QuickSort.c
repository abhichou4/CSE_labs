#include <stdio.h>

void swap(int* a, int* b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){

	int pivot, i, j;
	i = low - 1;
	pivot = arr[high];

	for(j=0; j<high; j++){

		if(arr[j] <= pivot){
			i++;
			swap(&arr[j], &arr[i]);
		}
	}

	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void QuickSort(int arr[], int low, int high){

	if(low < high){
		int p = partition(arr, low, high);

		QuickSort(arr, low, p-1);
		QuickSort(arr, p+1, high);
	}
}

int main(void){
	int i, n;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	QuickSort(a, 0, n-1);
	for(i=0; i<n; i++){
		printf("%d\n", a[i]);
	}
	return 0;
}