#include <stdio.h>
#include <string.h>

int string_match(char string[], char sub_string[]) {
	int flag;
	for (int i=0; i<strlen(string)-strlen(sub_string)+1; i++) {
		flag = 1;
		for (int j=0; j<strlen(sub_string); j++) {
			if (string[i+j]!=sub_string[j]) {
				flag = 0; 
				break;
			}
		}
		if (flag==1){
			return flag;
		}
	}
	return flag;
}

int main(void) {
	char *str, *sub_str;
	printf("Enter string:\n");
	scanf("%ms", &str);
	printf("Enter Sub-String:\n");
	scanf("%ms", &sub_str);
	if (string_match(str, sub_str))
		printf("Sub-String Present\n");
	else 
		printf("Sub-String Absent\n");
	return 0;
}