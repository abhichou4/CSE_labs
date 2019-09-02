#include <stdio.h>

int main(void){

	int no_test;
	scanf("%d", &no_test);
	char arr[2*no_test][20000];
	int i;
	for(i=0; i<2*no_test; i++){
		scanf("%s", arr[i]);
	}
	int j;
	for(i=0; i<2*no_test; i+2){
		char buff[20000]; j=0;
		while(arr[i][j]!='\0'){
			buff[j]=arr[i+1][j]-arr[i][j]; j++;
		}
		printf("%s\n", buff);
	}
}