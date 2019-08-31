#include <stdio.h>

char* find_capital(char* p, int len){

	if(*p>'A' && *p<'Z'){
		return p;
	}

	if(*p == *(p+len-1)){
		return NULL;
	}

	return find_capital(++p, len);
}

int main(){

	int len;
	char *ptr=NULL, *p=NULL;
	printf("Enter string\n");
	scanf("%ms", &ptr);
	while(*(ptr+len) != '\0'){
		len++;
	}
	char* front=ptr;
	p = find_capital(ptr, len);
	int position = p - front + 1;

	if(p==NULL){
		printf("No capital letters!\n");
	}

	else{
		printf("%c is the first captial letter at %d position\n", *p, position);
	}
}