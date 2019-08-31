#include <stdio.h>

int rev_and_print(char arr[], int len){

	if(len<=1){
		return 0;
	}
	printf("%c", arr[len-1]);
	rev_and_print(arr, --len);
}

int main(){

	char str[100];
	int len;
	printf("Enter line\n");
	scanf("%[^\n]%*c", str);
	while(*(str+len) != '\0'){
		len++;
	}
	str[len]=' ';
	int i = rev_and_print(str, len);
	return i;
}