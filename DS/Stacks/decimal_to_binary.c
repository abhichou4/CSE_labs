#include <stdio.h>
#include "array_stack.h"

int main(void){

	int num;
	printf("Enter decimal number\n");
	scanf("%d", &num);

	stack* s;
	s->top=-1;

	while(num!=0){
		push(s, (num%2));
		num /= 2;
	}

	rev_display(s);

}