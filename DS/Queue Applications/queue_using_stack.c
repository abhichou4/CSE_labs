#include <stdio.h>
#include "array_stack.h"

int queue_full(stack* s1, stack* s2){
	return(isFull(s1));
}

int queue_empty(stack* s1, stack* s2){
	return(isEmpty(s1) && isEmpty(s2));
}

void enqueue(stack* s1, stack* s2, char ele){
	if(!queue_full(s1, s2)){
		push(s1, ele);
		printf("------- %c ADDED TO QUEUE -------\n", ele);
	}
	else printf("------ QUEUE IS FULL! -------\n");
}

int dequeue(stack* s1, stack* s2){
	char ele;
	if(!queue_empty(s1, s2)){
		if(isEmpty(s2)){
			while(!isEmpty(s1)){
				int temp = pop(s1);
				push(s2, temp);
			}
		}
		ele = pop(s2);
		printf("------- %c DELETED FROM QUEUE ------\n", ele);
		return ele;
	}
	else{
		printf("------ QUEUE IS EMPTY! --------\n");
		return '#';
	}
}

int main(){
	stack* stack1 = make_stack(5);
	stack* stack2 = make_stack(5);
	enqueue(stack1, stack2, '0');
	enqueue(stack1, stack2, '1');
	enqueue(stack1, stack2, '2');
	dequeue(stack1, stack2);
	dequeue(stack1, stack2);
	enqueue(stack1, stack2, '3');
	dequeue(stack1, stack2);
	dequeue(stack1, stack2);
	dequeue(stack1, stack2);
	dequeue(stack1, stack2);
}