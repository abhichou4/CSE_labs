#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int* heap_bottom_up(int* arr, int n) {
	for (int i=n/2; i>=1; i--) {
		int k=i; int v=arr[i];
		bool heap = false;
		while (!heap && 2*k<n) {
			int j=2*k;
			if (j<=n){
				if (arr[j] < arr[j+1]) j=j+1;
				if (v > arr[j]) heap=true;
				else {arr[k]=arr[j]; k=j;}
			}
		}
		arr[k]=v;
	}
	return arr;
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