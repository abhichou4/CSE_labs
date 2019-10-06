#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int key;
	struct node *left, *right;
};

void create_tree_rec(struct node** root){
	int ele;
	if(*root==NULL){
		printf("Enter element\n");
		scanf("%d", &ele);
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->key = ele;
		(*root)->right=NULL;
		(*root)->left=NULL;
		return;
	}
	printf("Enter to left or right of %d\n", (*root)->key);
	char* choice;
	scanf("%ms", &choice);
	if(!strcmp(choice, "left")){
		printf("%d", strcmp(choice, "left"));
		create_tree_rec(&(*root)->left);
	}
	else
		create_tree_rec(&(*root)->right);
}

void inorder_tranv(struct node* root){
	if(root!=NULL){
		inorder_tranv(root->left);
		printf("%d  ", root->key);
		inorder_tranv(root->right);
	}
	else return;
}

void preorder_tranv(struct node* root){
	if(root!=NULL){
		printf("%d", root->key);
		preorder_tranv(root->left);
		preorder_tranv(root->right);
	}
	else return;
}

void postorder_trav(struct node* root){
	if(root!=NULL){
		postorder_trav(root->left);
		postorder_trav(root->right);
		printf("%d  ", root->key);
	}
	else return;
}

int main(void){
	printf("---Create binary tree---\n");
	char c;
	struct node* root = NULL;
	do{
		create_tree_rec(&root);
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y' | c=='Y');
	printf("In Order :\n");
	inorder_tranv(root);
	printf("Pre Order :\n");
	preorder_tranv(root);
	printf("Post Order\n");
	postorder_trav(root);
}