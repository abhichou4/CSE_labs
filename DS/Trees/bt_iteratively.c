#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array_stack.h"

struct node* create_bt_iter(struct node* root){
	int ele; char* choice; 
	struct node* temp=NULL;
	struct node* hold_root = root;
	printf("Enter element to add\n");
	scanf("%d", &ele);
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->right=NULL;
	temp->left=NULL;
	if(root==NULL){
		root = temp;
		return root;
	}
	else{
		while(1){
			printf("Add node to left or right of %d\n", root->data);
			scanf("%ms", &choice);
			if(!strcmp(choice, "left")){
				if(root->left==NULL){
					root->left=temp;
					break;
				}
				else 
					root=root->left;
			}
			else{
				if(root->right==NULL){
					root->right=temp;
					break;
				}
				else 
					root=root->right;
			}
		}
		return hold_root;
	}
}



void inorder_iter(struct node* root){
	stack s;
	s.top = -1;
	struct node* current = root;
	while(!isEmpty(&s) || current!=NULL){
		if(current!=NULL){
			push(&s, current);
			current = current->left;
		}
		else{
			current = pop(&s);
			printf("%d  ", current->data);
			current = current->right;
		}
	}

}

void preorder_iter(struct node* root){
	stack s;
	s.top = -1;
	struct node* current = root;
	while(!isEmpty(&s) || current!=NULL){
		if(current!=NULL){
			push(&s, current);
			printf("%d  ", current->data);
			current = current->left;
		}
		else{
			current = pop(&s);
			current = current->right;
		}
	}
}
/*
void postorder_iter(struct node* root){
	stack s;
	s.top = -1;
	struct node* current = root;
	while(!isEmpty(&s) || current!=NULL){
		if(current!=NULL){
			push(&s, current);
			printf("%d  ", current->data);
			current = current->left;
		}
		else{
			current = pop(&s);
			current = current->right;
		}
	}
}
*/
int main(void){
	struct node* root=NULL;
	char c;
	do{
		root=create_bt_iter(root);
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y' | c=='Y');
	printf("In Order :\n");
	inorder_iter(root);
	printf("Pre Order :\n");
	preorder_iter(root);
}