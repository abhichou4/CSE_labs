// Delete Strong Numbers from an array recursively 

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
	if (n < 2)
		return n;
	return fib(n-1) + fib(n-2); 
}

//TODO: Make this recursive, possibly one func
int fib_sum(int n) {
	int sum = 0;
	for (int i=1; i<n; i++) 
		sum += fib(i);
	return sum;
}

void delete_strongs(int* arr, int n) {
	int count = 0;  
	for (int i=0; i<n; i++) {
		if (arr[i] == fib_sum(arr[i])) {
			for(int j=i+1; j<n-count; j++) 
				arr[j-1] = arr[j];
			arr[n-count-1] = 0;
			count++;
		}
	}
} 

int main(void) {
	int n;
	printf("Enter number of elements:\n");
	scanf("%d", &n);
	printf("Enter elements:\n");
	int* arr = (int*)malloc(sizeof(int)*n);
	for (int i=0; i<n; i++)  
		scanf("%d", arr+i);
	printf("Original array:\n");
	for (int j=0; j<n; j++)  
		printf("%d ", arr[j]);
	delete_strongs(arr, n);
	printf("\n");
	printf("Result array:\n");
	for (int i=0; i<n; i++)  
		printf("%d ", arr[i]);
	printf("\n");
 }
