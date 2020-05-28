#include <stdio.h>
#include <stdlib.h>

int* sort_index(int* arr, int n) {
    int* idx = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) 
        idx[i] = 0;
    for (int j=0; j<n-1; j++) {
        for (int k=j+1; k<n; k++) {
            if (arr[k]<=arr[j]) 
                idx[j]++;
            else 
                idx[k]++;
        }
    }
    
    int* sorted = (int*)malloc(sizeof(int)*n);
    for (int l=0; l<n; l++)
        sorted[idx[l]] = arr[l];
    return sorted;
}

int main(void) {
    int n;
    printf("enter number of elements:");
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int)*n);
    printf("enter elements:");
    for (int i=0; i<n; i++) 
        scanf("%d", arr+i);
    int* sorted = sort_index(arr, n);
    for (int j=0; j<n; j++) {
        printf("%d  ", sorted[j]);
    }
    return 0;
}