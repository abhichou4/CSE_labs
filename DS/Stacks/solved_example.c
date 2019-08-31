#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int top;
	char* arr;
} stack;

stack* make_stack(int len){
	stack* s;
	s = (stack*)malloc((sizeof(stack)));
	s->top = -1;
	s->arr = (char*)malloc(len*(sizeof(char)));
	return s;
}

void push(stack* s, char ele){
	s->arr[++(s->top)]=ele;
	printf("%c pushed at %d\n", ele, s->top);
}

void pop(stack* s){
	char ele = s->arr[(s->top)--];
	printf("%c popped from %d\n", ele, (s->top)+1);
}

int main(void){

	char arr[100];
	printf("Enter the expression to be checked\n");
	scanf("%s", arr);
	int len = strlen(arr);

	stack* s = make_stack(len);

	int i=0; int balance=1; char buff;
	while(arr[i]!='\0' && balance==1){

		if (arr[i]=='(') push(s,'(');

		else if (arr[i]==')'){
			if (s->top == -1) balance=0;
			else{
				pop(s);
			}
		}
		i++;
	}

	if(balance==0 || s->top!=-1) printf("Expression is not well formed.\n");
	else printf("Expression is well formed\n"); 
}