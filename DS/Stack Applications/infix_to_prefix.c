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
		case ')': return 0;
	}
	return -1;
}

void rev_string(char* str){
	char temp;
	for(int i=0; i<strlen(str)/2; i++){
		temp=str[i];
		str[i]=str[strlen(str)-i-1];
		str[strlen(str)-i-1]=temp;
	}
	return;
}

void infix_to_prefix(char* infix, char* prefix){
	rev_string(infix);
	*(infix+strlen(infix))='(';
	int i, k; char c;
	stack* stk = make_stack(strlen(infix));
	push(stk, ')');
	for(i=0, k=-1; infix[i]!='\0'; i++){
		if(isOperand(infix[i])){
			prefix[++k]=infix[i];
		}
		else if (infix[i]==')'){
			push(stk, ')');
		}
		else if (infix[i]=='('){
			while(peek(stk)!=')'){
				prefix[++k]=pop(stk);
			}
			c=pop(stk);
		}
		else if (infix[i]=='^'){
			if (peek(stk)=='^'){
				prefix[++k]=pop(stk);
				push(stk, infix[i]);
			}
			else{
				push(stk, infix[i]);
			}
		}
		else{
			while(Pref(peek(stk)) > Pref(infix[i])){
				prefix[++k] = pop(stk);
			}
			push(stk, infix[i]);
		}
	}
	rev_string(prefix);
	return;
}

int main(){

	printf("Enter intfix expression\n");
	char* infix;
	scanf("%ms", &infix);
	int len = strlen(infix);
	char* prefix;
	prefix = (char*) malloc(len*sizeof(char));

	infix_to_prefix(infix, prefix);
	puts(prefix);
}