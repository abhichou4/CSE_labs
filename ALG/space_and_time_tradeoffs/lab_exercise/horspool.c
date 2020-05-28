#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* shift_table(char* pattern) {
	int len = strlen(pattern);
	int* table = (int*)malloc(sizeof(int)*128);
	for (int i=0; i<128; i++) {table[i]=len;}
	for (int j=0; j<len-1; j++) {table[(int)pattern[j]] = len-1-j;}
	return table;
}

int match_count(char* text, char* pattern) {
	printf("Text: %s\nPatten: %s\n", text, pattern);
	int text_len = strlen(text);
	int pattern_len = strlen(pattern);
	int shift, count=0;
	printf("Text Length: %d\nPattern Lenghth: %d\n", text_len, pattern_len);
	int* shift_t = shift_table(pattern);
	printf("Shift Table\n");
	printf("--------\n");
	for (int i=0; i < pattern_len; i++) 
		printf("|%c | %d|\n", pattern[i], shift_t[(int)pattern[i]]);
	printf("--------\n");
	for (int j=0; j < text_len - pattern_len + 1; j=j+shift) {
		int k=pattern_len-1;
		while (text[j+k]==pattern[k] && k!=0) {
			printf("%c == %c\n", text[j+k], pattern[k]);
			k--;
		}
		if (k==0) {
			count++;
			shift=6;
		}
		else {
			shift=shift_t[(int)text[j+k]];
			printf("Shift by --> %d\n", shift);
		}
	}
	return count;
}

int main(void) {
	char* pattern = "BARBER";
	char* text = "TEXTBARBERTEXTdjgBARBERzLDKzgjsBARBERakjlsjfhBARBERAKJSfhBARBER";
	int* table = shift_table(pattern);
	printf("count: %d\n", match_count(text, pattern));
}