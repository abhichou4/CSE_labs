#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *right, *left;
};

struct node* make_node(int data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
}

void create_bst_recursive(struct node** first, int ele){
	if(*first==NULL){
		*first = make_node(ele);
		return;
	}
	else{
		if(ele > (*first)->data)
			create_bst_recursive(&(*first)->right, ele);
		else if(ele < (*first)->data)
			create_bst_recursive(&(*first)->left, ele);
		else 
			return;
	}
}

struct node* create_bst_iteravtive(struct node* first, int ele){
	if(first==NULL)
		first = make_node(ele);
	else{
		struct node* trav = first;
		while(1){
			if(ele > trav->data){
				if(trav->right==NULL)
					trav->right = make_node(ele);
				trav = trav->right;
			}
			else if(ele < trav->data){
				if(trav->left==NULL){
					trav->left = make_node(ele);
				trav = trav->left;
				}
			}
			else 
				break;
		}
	}
	return first;
}

//find a node 
struct node* find_node(struct node* root, int ele){
	if(root->data==ele)
		return root;
	else{
		if(ele>root->data)
			return find_node(root->right, ele);
		else 
			return find_node(root->left, ele);
	}
}

struct node* delete_node(struct node* root, int ele){
	struct node* ptr = find_node(root, ele);
	if(ptr->left!=NULL){
		struct node* max_node = ptr->left;
		while(max_node->right->right!=NULL)
			max_node = max_node->right;
		ptr->data = max_node->right->data;
		free(max_node->right);
		max_node->right = NULL;
	}
	else if(ptr->right!=NULL){
		struct node* min_node = ptr->right;
		while(min_node->left->left!=NULL)
			min_node = min_node->left;
		ptr->data = min_node->left->data;
		free(min_node->left);
		min_node->left = NULL;
	}
	else{
		free(ptr);
	}
	return root;
}

void inorder_trav_recursive(struct node* root){
	if(root==NULL)
		return;
	else{
		inorder_trav_recursive(root->left);
		printf("%d  ", root->data);
		inorder_trav_recursive(root->right);
	}
}

int main(void){
	struct node* first = NULL;
	char c; int ele;
	do{
		printf("Enter Data\n");
		scanf("%d", &ele);
		create_bst_recursive(&first, ele);
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y' || c=='Y');
	inorder_trav_recursive(first);
	first = delete_node(first, 10);
	printf("\n");
	inorder_trav_recursive(first);
	printf("\n");
}