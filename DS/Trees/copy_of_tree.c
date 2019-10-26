#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node *right, *left;
};

struct node* make_node(int data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

struct node* create_tree_iterative(struct node* root){
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

void inorder_recursive(struct node* root){
	if(root!=NULL){
		inorder_recursive(root->left);
		printf("%d  ", root->data);
		inorder_recursive(root->right);
	}
	else
		return;
}

struct node* create_copy(struct node* root){
	if(root==NULL)
		return NULL;
	else{
		struct node* copy = make_node(root->data);
		if(root->left!=NULL)
			copy->left = create_copy(root->left);
		if(root->right!=NULL)
			copy->right = create_copy(root->right);
		return copy;
	}
}

int main(void){
	struct node* t1 = NULL;
	char c;
	do{
		t1 = create_tree_iterative(t1);
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y'||c=='Y');
	struct node* t2 = create_copy(t1);
	inorder_recursive(t1);
	printf("\n");
	inorder_recursive(t2);
	printf("\n");
}