#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* bubble_sort(int arr[], int n) {
	for (int k=0; k<n-1; k++) {
		for (int i=k; i<n-1; i++) {
			if (arr[i] > arr[i+1])
				swap(&arr[i], &arr[i+1]);
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
	sorted = bubble_sort(arr, n);
	printf("Sorted:\n");
	for (int j=0 ; j<n; j++)
		printf("%d\n", sorted[j]);
}