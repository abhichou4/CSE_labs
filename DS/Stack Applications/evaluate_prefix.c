#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_stack.h"

void rev_string(char* str){
	char temp;
	for(int i=0; i<strlen(str)/2; i++){
		temp=str[i];
		str[i]=str[strlen(str)-i-1];
		str[strlen(str)-i-1]=temp;
	}
	return;
}

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

char eval_prefix(char* prefix){
	rev_string(prefix);
	puts(prefix);
	stack* stk = make_stack(strlen(prefix));
	for(int i=0; prefix[i]!='\0'; i++){

		if(isdigit(prefix[i])) push(stk, prefix[i]);

		else{
			char e1 = pop(stk);
			char e2 = pop(stk);
			push(stk, Ops(e1, e2, prefix[i]));
		}
	}
	return(pop(stk));
}

int main(){
	printf("Enter prefix expression\n");
	char* buff;
	scanf("%ms", &buff);
	char value = eval_prefix(buff);
	printf("%c\n", value);
}