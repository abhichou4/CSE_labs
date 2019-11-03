#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left, *right;
};

struct node* make_node(int data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void create_bst_recursive(struct node** root, int ele){
	if(*root==NULL){
		*root = make_node(ele);
		return;
	}
	if(ele < (*root)->data)
		create_bst_recursive(&(*root)->left, ele);
	else if(ele > (*root)->data)
		create_bst_recursive(&(*root)->right, ele);
	else 
		return;
}

struct node* create_bst_iterative(struct node* root, int ele){
	struct node* new_node = make_node(ele);
	if(root==NULL){
		root= new_node;
		return root;
	}
	struct node* trav = root;
	while(trav!=NULL){
		if(ele < trav->data){
			if(trav->left==NULL)
				trav->left = new_node; 
			trav = trav->left;
		}
		else if(ele > trav->data){
			if(trav->right==NULL)
				trav->right = new_node;
			trav = trav->right;
		}
		else 
			break;
	}
	return root;
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

int main(void){
	struct node* root = NULL;
	int arr[15] = {13, 3, 4, 12, 14, 10, 5, 1, 8, 2, 7, 9, 11, 6, 18};
	for(int i=0; i<15; i++)
		create_bst_recursive(&root, arr[i]);
	inorder_recursive(root);
	printf("\n");
}