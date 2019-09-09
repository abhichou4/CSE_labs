#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 100

struct twod_stack{
	int top;
	char arr[100][100];
};

int isFull(struct twod_stack* s){
	return(s->top+1==MAX_LEN);
}

int isEmpty(struct twod_stack* s){
	return(s->top==-1);
}

void push(struct twod_stack* s, char* ele){
	printf("%s\n", ele);
	if(!isFull(s)){
		strcpy(s->arr[++s->top], ele);
	}
	else {
		printf("Stack Overflow!\n");
		exit(0);
	}
}

char* pop(struct twod_stack* s){
	if(!isEmpty(s)){
		return s->arr[s->top--];
	}
	else{
		printf("Stack Underflow!\n");
		exit(0);
	}
}

void rev_string(char* str){
	int i;
	char temp;
	for(i=0; i<strlen(str)/2; i++){
		temp=str[i]; 
		str[i]=str[strlen(str)-i-1]; 
		str[strlen(str)-1-i]=temp;
	}
}

char* prefix_to_postfix(char* prefix){

	rev_string(prefix);
	printf("%s\n", prefix);
	struct twod_stack s;
	int i;
	for(i=0; prefix[i]!='\0'; i++){

		if(isalpha(prefix[i])){
			char temp[] = {prefix[i], '\0'};
			push(&s, temp);
		}
		else{
			char* e1 = pop(&s);
			printf("%s\n", e1);
			char* e2 = pop(&s);
			printf("%s\n", e2);
			char temp[] = {prefix[i], '\0'};
			strcat(temp, e2);
			strcat(temp, e1);
			push(&s, temp);
			printf("%s\n", temp);
		}
	}

	char* postfix = pop(&s);
	rev_string(postfix);
	return postfix;
}

int main(void){

	printf("Enter the prefix expression\n");
	char* prefix;
	scanf("%ms", &prefix);
	char* postfix = (char*)malloc(strlen(prefix)*sizeof(char));
	postfix = prefix_to_postfix(prefix);
	printf("%s\n", postfix);
}