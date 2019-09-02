#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_stack.h"

char Ops(char e1, char e2, char op){
	switch(op){
		case '+': ;
			int res = e1-'0' + e2-'0';
			return res + '0';

		case '-': ;
			res = e1-'0' - e2-'0';
			return res + '0';

		case '*': ;
			res = (e1-'0')*(e2-'0');
			return res + '0';

		case '/': ;
			res = (e2-'0')/(e1-'0');
			return res + '0';
	}
}

char eval_postfix(char* postfix){

	stack* stk = make_stack(strlen(postfix));
	for(int i=0; postfix[i]!='\0'; i++){

		if(isdigit(postfix[i])) push(stk, postfix[i]);

		else{
			char e1 = pop(stk);
			char e2 = pop(stk);
			push(stk, Ops(e1, e2, postfix[i]));
		}
	}
	return(pop(stk));
}

int main(){
	printf("Enter postfix expression\n");
	char* buff;
	scanf("%ms", &buff);
	char value = eval_postfix(buff);
	printf("%c\n", value);
}