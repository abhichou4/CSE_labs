#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void shiftUp(int* arr, int start, int end) {
	int c = end;
	while (c > start) {
		int p = c/2;
		if (arr[p] < arr[c]) {
			swap(arr+p, arr+c);
			c = p;
		}
		else return;
	}
}

void heapify(int* arr, int n) {
	int end = 1;
	while (end <= n) {
		shiftUp(arr, 1, end);
		end++;
	}
}

void heapsort(int* arr, int n) {
	heapify(arr, n);
	for (int i=n; i>1; i--) {
		swap(arr+i, arr);
		heapify(arr, i-1);
	}
}

int main(void) {

	int n;
	printf("Enter number of elements:\n");
	scanf("%d", &n);
	int* arr = (int*)calloc(n+1, sizeof(int));
	printf("Enter elements:\n");
	for (int i=1; i<=n; i++) 
		scanf("%d", &arr[i]);
	heapsort(arr, n);
	for (int i=1; i<=n; i++) 
		printf("%d ", arr[i]);
}