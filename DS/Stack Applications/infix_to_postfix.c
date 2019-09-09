#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_stack.h"

int isOperand(char ch){
	return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <='Z');
}

int Pref(char ch){
	switch(ch){
		case '^': return 3;
		case '*':
		case '/': return 2;
		case '+':
		case '-': return 1;
		case '(': return 0;
	}
	return -1;
}

void infix_to_postfix(char* infix, char* postfix){
	int i, k; char c;
	stack* stk = make_stack(strlen(infix));
	push(stk, '(');
	for(i=0, k=-1; infix[i]!='\0'; i++){
		if(isOperand(infix[i])){
			postfix[++k]=infix[i];
		}
		else if (infix[i]=='('){
			push(stk, '(');
		}
		else if (infix[i]==')'){
			c = pop(stk);
			while(c!='('){
				postfix[++k]=c;
				c = pop(stk);
			}
		}
		else if (infix[i]=='^'){
			if (peek(stk)=='^'){
				push(stk, infix[i]);
			}
			else{
				while(Pref(peek(stk)) >= Pref(infix[i])){
					postfix[++k] = pop(stk);
				}
				push(stk, infix[i]);
			}
		}
		else{
			while(Pref(peek(stk)) >= Pref(infix[i])){
				postfix[++k] = pop(stk);
			}
			push(stk, infix[i]);
		}
	}
	return;
}


int main(){

	printf("Enter intfix expression\n");
	char* infix;
	scanf("%ms", &infix);
	int len = strlen(infix);
	*(infix+len)=')';
	char* postfix;
	postfix = (char*) malloc(len*sizeof(char));

	infix_to_postfix(infix, postfix);
	puts(postfix);
}