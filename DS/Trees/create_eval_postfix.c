#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 10
#define true 1
#define false 0

//char tree
struct node{
	char data;
	struct node *right, *left;
};

//array stack 
typedef struct{
	struct node* arr[MAX_LEN];
	int top;
} stack;

int isFull(stack* s){
	if(s->top==MAX_LEN-1) return true;
	else return false;
}

int isEmpty(stack *s){
	if(s->top==-1) return true;
	else return false;
}

void push(stack* s, struct node* node){
	if(!isFull(s)) {
		s->arr[++(s->top)] = node;
		//printf("%d pushed to stack at %d\n", node->data, s->top);
	}
	else return; //printf("Stack Overflow\n");
}

struct node* pop(stack* s){
	if(!isEmpty(s)) {
		struct node* node = s->arr[(s->top)--]; 
		//printf("%d popped from stack at %d\n", node->data, (s->top)+1);
		return node;
	}
	else{
		//	printf("Stack Underflow\n");
		return NULL;
	}
}

void display(stack* s){
	if(s->top==-1){
		return; //printf("Stack is empty.\n");
	}
	int i=0;
	while(i<=s->top){
		printf("%c  ", (s->arr[i++])->data);
	}
	printf("\n");
}

//utility functions
struct node* make_node(char data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

int isOperand(char c){
	if((c>'a' && c<'z') || (c>'A' && c<'Z'))
		return true;
	else 
		return false;
}

void postorder_iterative_2stack(struct node* root){
	stack s1, s2;
	s1.top = -1; s2.top=-1;
	push(&s1, root);
	while(!isEmpty(&s1)){
		root=pop(&s1);
		push(&s2, root);
		if(root->left!=NULL)
			push(&s1, root->left);
		if(root->right!=NULL)
			push(&s1, root->right);
	}
	struct node* node = NULL;
	while(!isEmpty(&s2)){
		node = pop(&s2);
		printf("%c  ", node->data);
	}
}

//create expression tree
struct node* expression_tree_postfix(char* postfix){
	if(postfix==NULL)
		return NULL;
	stack s;
	s.top = -1;
	for(int i=0; i<strlen(postfix); i++){
		if(isOperand(postfix[i]))
			push(&s, make_node(postfix[i]));
		else{
			struct node* root_node = NULL;
			root_node = make_node(postfix[i]);
			root_node->right = pop(&s);
			root_node->left = pop(&s);
			push(&s, root_node);
		}
	}
	return pop(&s);
}

int main(void){
	printf("Enter expression\n");
	char postfix[MAX_LEN];
	scanf("%s", postfix);
	puts(postfix);
	struct node* exp_tree = expression_tree_postfix(postfix);
	postorder_iterative_2stack(exp_tree);
	printf("\n");
}