#include <stdio.h>
#include <string.h>

int isPalin(char *p, int s, int e){

	if(s==e){
		return 1;
	}

	if(p[s]!=p[e]){
		return 0;
	}

	return isPalin(p, s+1, e-1);
}

int ZeroisPalin(char *p){
	int n = strlen(p);

	if(n==0){
		return 1;
	}

	return isPalin(p, 0, n-1);
}

int main(){

	printf("Enter string\n");
	char *buff;
	scanf("%ms", &buff);
	if(ZeroisPalin(buff)){
		printf("Is Palindrome.\n");
	}
	else{
		printf("Is not Palindrome.\n");
	}
}