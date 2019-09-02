#include <stdio.h>
#include <string.h>
#include "array_stack.h"

int main(void){
	printf("Enter string\n");
	char *buff;
	scanf("%ms", &buff);
	stack* s; 
	s->top=-1;
	int i=0;
	push(s, buff[i]); i++;
	while(buff[i]!='\0'){
		if(s->arr[s->top]==buff[i]){
			pop(s);
		}
		
		else{
			push(s, buff[i]);
		}
		if(strlen(buff)%2==1 && i==(int)strlen(buff)/2){
			pop(s);
		}
		i++;
	}

	if(isEmpty(s)){
		printf("Is a palindrome.\n");
	}
	else{
		printf("Is not a palindrome\n");
	}
}