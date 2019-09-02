#include <stdio.h>
#include <stdlib.h>
#include "array_stack.h"

stack* make_stack(int size){
	stack* s;
	s = (stack*) malloc(sizeof(stack));
	s->top = -1;
	s->arr = (char*)malloc(size*sizeof(char));
	s->capacity = size;
	return s;
}

int isFull(stack* s){
	if(s->top==s->capacity-1) return true;
	else return false;
}

int isEmpty(stack *s){
	if(s->top==-1) return true;
	else return false;
}

void push(stack* s, char ele){
	if(!isFull(s)) {s->arr[++(s->top)] = ele; printf("%c pushed to stack at %d\n", ele, s->top);}
	else printf("Stack Overflow\n");
}

char pop(stack* s){
	if(!isEmpty(s)) {char ele = s->arr[(s->top)--]; printf("%c popped from stack at %d\n", ele, (s->top)+1); return ele;}
	else printf("Stack Underflow\n"); return -1;
}

char peek(stack* s){
	return s->arr[s->top];
}

void display(stack* s){
	if(s->top==-1){
		printf("Stack is empty.\n");
	}
	int i=0;
	while(i<=s->top){
		printf("%c ", s->arr[i++]);
	}
	printf("\n");
}
