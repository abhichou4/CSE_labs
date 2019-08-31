#include <stdio.h>
#include <string.h>

int Cap(char* p, int s, int e){
	if(s>e){
		return -1;
	}
	if(p[s]>='A' && p[s]<='Z'){
		return s;
	}
	return Cap(p, ++s, e);
}

int ZeroCap(char* p){
	int n = strlen(p);
	if(n==0){
		return -1;
	}
	else{
		Cap(p, 0, n-1);
	}
}

int main(){

	printf("Enter string\n");
	char* buff;
	scanf("%ms", &buff);
	int s = ZeroCap(buff);
	if(s==-1){
		printf("No Cap\n");
	}
	else{
		printf("%d\n", s+1);
	}
}