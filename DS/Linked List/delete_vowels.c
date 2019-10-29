#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char data;
	struct node* next;
};

struct node* make_node(char data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

struct node* append_node(struct node* first, char data){
	struct node* new_node = make_node(data);
	if(first==NULL){
		first = new_node;
		return first;
	}
	struct node* trav = first;
	while(trav->next!=NULL)
		trav = trav->next;
	trav->next = new_node;
	return first;
}

void display(struct node* first){
	while(first!=NULL){
		printf("%c  ", first->data);
		first = first->next;
	}
}

struct node* make_ll(struct node* first, char* str){
	int i=0;
	while(i<strlen(str)){
		first = append_node(first, str[i]);
		i++;
	}
	return first;
}

int isVowel(char c){
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 1;
		default:
			return 0;
	}
}

struct node* delete_vowels(struct node* first){
	struct node* trail = first;
	struct node* temp = NULL;
	while(isVowel(first->data)){
		temp = first;
		first = first->next;
		free(temp);
	}
	while(trail->next!=NULL){
		if(isVowel(trail->next->data)){
			temp = trail->next;
			trail->next = trail->next->next;
			free(temp);
		}
		else 
			trail = trail->next;
	}
	return first;
}

int main(){
	printf("enter string\n");
	char* buff;
	scanf("%ms", &buff);
	struct node* first = NULL;
	first = make_ll(first, buff);
	first = delete_vowels(first);
	display(first);
	printf("\n");
}