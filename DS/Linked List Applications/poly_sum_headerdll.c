#include <stdio.h>
#include <stdlib.h>

/*
circular doubly linked list
*/

struct node{
	int expo, coeff;
	struct node *left, *right;
};

struct node* add_to_dll(struct node* node, int expo, int coeff);
struct node* delete_from_dll(struct node* node);
void display(struct node* header);
struct node* create_header_dll(struct node* header);
struct node* sum_of_poly(struct node* poly1, struct node* poly2);

int main(void){
	struct node *poly1=NULL, *poly2=NULL, *result=NULL;
	poly1 = create_header_dll(poly1);
	poly2 = create_header_dll(poly2);
	result = sum_of_poly(poly1, poly2);
	display(poly1);
	display(poly2);
	display(result);
}

struct node* add_to_dll(struct node* node, int expo, int coeff){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->expo = expo;
	new_node->coeff = coeff;
	if(node==NULL){
		node = (struct node*)malloc(sizeof(struct node));
		node->coeff=0;
		node->expo=0;
		node->right = new_node;
		new_node->left = node;
		node->left = new_node;
		new_node->right = node;
	}
	else{
		new_node->left = node->left;
		new_node->right = node;
		node->left->right = new_node;
		node->left = new_node;
	}
	return node;
}

struct node* delete_from_dll(struct node* node){
	if(node->left==NULL && node->right==NULL) printf("Empty list\n"); 
	else{
		struct node* temp = node->right;
		node->right = node->right->right;
		node->right->left = node;
		free(temp);
	}
	return node;
}

void display(struct node* header){
	struct node* ptr = header;
	ptr = ptr->right;
	while(ptr!=header){
		printf("%dx^%d + ", ptr->coeff, ptr->expo);
		ptr = ptr->right;
	}
	printf("\n");
}

struct node* create_header_dll(struct node* header){
	int choice, expo, coeff; char c;
	struct node* ptr = NULL;

	do{
		printf("1. Add node\n2. Delete Node\n3. Display\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter exponent and coeff\n");
				scanf("%d", &expo);
				scanf("%d", &coeff);
				ptr = add_to_dll(ptr, expo, coeff);
				break;

			case 2:
				ptr = delete_from_dll(ptr);
				break;

			case 3:
				display(ptr);
				break;

			default:
				printf("Enter valid option\n");
		}
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y' | c=='Y');

	return ptr;
}

struct node* sum_of_poly(struct node* poly1, struct node* poly2){
	struct node *ptr1=poly1, *ptr2=poly2;
	struct node* result=NULL;
	ptr1 = ptr1->right; ptr2 = ptr2->right;
	while(!(ptr1==poly1 && ptr2==poly2)){
		printf("INN\n");
		if(ptr1==poly1){
			printf("ptr1==poly1\n");
			result = add_to_dll(result, ptr2->expo, ptr2->coeff);
			ptr2 = ptr2->right;
		}
		else if(ptr2==poly2){
			printf("ptr2==poly2\n");
			result = add_to_dll(result, ptr1->expo, ptr1->coeff);
			ptr1 = ptr1->right;
		}
		else if(ptr1->expo < ptr2->expo){
			printf("ptr1->expo < ptr2->expo\n");
			result = add_to_dll(result, ptr1->expo, ptr1->coeff);
			ptr1 = ptr1->right;
		}
		else if(ptr1->expo > ptr2->expo){
			printf("ptr1->expo > ptr2->expo\n");
			result = add_to_dll(result, ptr2->expo, ptr2->coeff);
			ptr2 = ptr2->right;
		}
		else{
			printf("exqual coeff\n");
			result = add_to_dll(result, ptr1->expo, (ptr1->coeff+ptr2->coeff));
			ptr1 = ptr1->right;
			ptr2 = ptr2->right;
		}
	}
	return result;
}