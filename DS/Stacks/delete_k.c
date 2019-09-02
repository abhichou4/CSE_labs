#include <stdio.h>
#include "array_stack.h"

int main(void){

	int n, k, i;
	printf("Enter n and k\n");
	scanf("%d", &n);
	scanf("%d", &k);
	int a[n];
	printf("Enter %d numbers\n", n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int count=0;
	stack ass;
	stack* s = &ass;
	s->top = -1;
	push(s, a[0]);
	for(i=1; i<n; i++){
		while(count<k && s->arr[s->top]<a[i]){
			pop(s);
			count++;
		}
		push(s, a[i]);
	}
	display(s);
}