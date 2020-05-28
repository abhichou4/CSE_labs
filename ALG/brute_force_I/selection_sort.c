#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* selection_sort(int arr[], int n) {
	for (int i=0; i<n; i++) {
		int idx=i, min = arr[i];
		for (int j=i; j<n; j++) {
			if (arr[j] < min) { 
				idx = j;
				min = arr[j];
			}
			swap(&arr[i], &arr[idx]);
		}
	}
	return arr;
} 

int main(void) {
	int n;
	printf("Enter length of array:\n");
	scanf("%d", &n);
	int arr[n];
	printf("Enter numbers\n");
	for (int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	int* sorted;
	sorted = selection_sort(arr, n);
	printf("Sorted:\n");
	for (int j=0 ; j<n; j++)
		printf("%d\n", sorted[j]);
}