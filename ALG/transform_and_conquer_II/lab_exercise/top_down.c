#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int* max_heap(int* arr, int n) {

	for(int i=1; i>=n/2; i++) {
		int k=i; int v=arr[i];
		bool heap = false;
		while ()
	}
}


int main(void) {

	int n;
	printf("Enter length of array:\n");
	scanf("%d", &n);
	int* arr = (int*)calloc(n+1, sizeof(int));
	printf("Enter Array:\n");
	for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
	int* max_heap = heap_bottom_up(arr, n);
	printf("Max Heap:\n");
	for (int i=1; i<=n; i++) printf("%d ", max_heap[i]);
	printf("\n");
	return 0;
}