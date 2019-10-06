#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *right, *left;
};

void display(struct node* ptr){
	while(ptr->left!=NULL)
		ptr = ptr->left;
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr = ptr->right;
	}
	printf("\n");
}

struct node* append_to_left(struct node* ptr, int ele){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data=ele;
	new_node->left=NULL;
	if(ptr==NULL){
		new_node->right=NULL;
		ptr = new_node;
	}
	else{
		struct node* left_most = ptr;
		while(left_most->left!=NULL)
			left_most = left_most->left;
		new_node->right=left_most;
		left_most->left=new_node;
	}
	return ptr;
}

struct node* append_to_right(struct node* ptr, int ele){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = ele;
	new_node->right=NULL;
	if(ptr==NULL){
		new_node->left = NULL;
		ptr = new_node;
	}
	else{
		struct node* right_most = ptr;
		while(right_most->right!=NULL)
			right_most = right_most->right;
		new_node->left = right_most;
		right_most->right = new_node;
	}
	return ptr;
}

void delete_from_left(struct node* ptr){
	struct node* temp = NULL;
	if(ptr==NULL) printf("List Empty!\n");
	else{
		while(ptr->left!=NULL)
			ptr = ptr->left;
		ptr->right->left = NULL;
		free(ptr);
	}
}

void delete_from_right(struct node* ptr){
	struct node* temp=NULL;
	if(ptr==NULL) printf("List Empty!\n");
	else{
		while(ptr->right!=NULL)
			ptr = ptr->right;
		ptr->left->right = NULL;
		free(ptr);
	}
}

int main(void){
	int choice, ele; char c;
	struct node* list = NULL;
	do{
		printf("1. Append to Right\n2. Append to left\n3. Delete from left\n4. Delete from right\n5. Display\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter element\n");
				scanf("%d", &ele);
				list = append_to_right(list, ele);
				break;
			case 2:
				printf("Enter element\n");
				scanf("%d", &ele);
				list = append_to_left(list, ele);
				break;
			case 3:
				delete_from_left(list);
				break;
			case 4:
				delete_from_right(list);
				break;
			case 5:
				display(list);
				break;
			default:
				printf("Enter valid option\n");
		}
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c == 'y' | c=='Y');
}