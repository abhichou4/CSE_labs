#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define true 1
#define false 0

typedef struct{
	char arr[MAX_LEN];
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

void push(stack* s, char ele){
	if(!isFull(s)) {s->arr[++(s->top)] = ele; printf("%c pushed to stack at %d\n", ele, s->top);}
	else printf("Stack Overflow\n");
}

void pop(stack* s){
	if(!isEmpty(s)) {char ele = s->arr[(s->top)--]; printf("%c popped from stack at %d\n", ele, (s->top)+1);}
	else printf("Stack Underflow\n");
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

int main(void){
	stack* s;
	s = (stack*)malloc(sizeof(stack));
	s->top = -1;
	char ch;	
	do{

		printf("Choose action to perform\n1.Push\n2.Pop\n3.Display\n");
		int choice; scanf("%d", &choice); 
		switch(choice){
			case 1: 
				printf("Enter element to push\n");
				char e; 
				scanf(" %c", &e);
				push(s,e);
				break;

			case 2:
				pop(s); 
				break;

			case 3:
				display(s); 
				break;

			default:
				printf("Enter valid choice\n");
		}

		printf("Continue? y or n\n");
		scanf(" %c", &ch);
	} while(ch=='y' || ch=='Y');
}