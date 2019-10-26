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

int check_equality(struct node* t1, struct node* t2){
	if(t1==NULL  && t2==NULL)
		return 1;
	if(t1==NULL  && t2!=NULL || t1!=NULL && t2==NULL)
		return 0;
	if(t1->data==t2->data)
		return(check_equality(t1->left, t2->left) && check_equality(t1->right, t2->right));
	else 
		return 0;
}

int main(void){
	struct node *root1=NULL, *root2=NULL;
	char c;

	do{
		root1 = create_tree_iterative(root1);
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y' || c=='Y');

	do{
		root2 = create_tree_iterative(root2);
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y' || c=='Y');	

	if(check_equality(root1, root2))
		printf("Trees are equal\n");
	else
		printf("Trees are not equal\n");
}