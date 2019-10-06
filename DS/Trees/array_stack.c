#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define true 1
#define false 0

struct node{
	int data;
	struct node *right, *left;
};

typedef struct{
	struct node* arr[MAX_LEN];
	int top;
} stack;

int isFull(stack* s){
	if(s->top==MAX_LEN-1) return true;
	else return false;
}

int isEmpty(stack *s){
	if(s->top==-1) return true;
	else return false;
}

void push(stack* s, struct node* node){
	if(!isFull(s)) {
		s->arr[++(s->top)] = node; 
		//printf("%d pushed to stack at %d\n", node->data, s->top);
	}
	else printf("Stack Overflow\n");
}

struct node* pop(stack* s){
	if(!isEmpty(s)) {
		struct node* node = s->arr[(s->top)--]; 
		//printf("%d popped from stack at %d\n", node->data, (s->top)+1);
		return node;
	}
	else printf("Stack Underflow\n");
}

void display(stack* s){
	if(s->top==-1){
		printf("Stack is empty.\n");
	}
	int i=0;
	while(i<=s->top){
		printf("%d ", (s->arr[i++])->data);
	}
	printf("\n");
}

