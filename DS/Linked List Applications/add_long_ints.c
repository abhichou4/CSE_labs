#include <stdio.h>
#include <stdlib.h>

struct node{
	int digit;
	struct node *right, *left;
};

struct node* add_node(struct node* header, int ele){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->digit = ele;
	if(header==NULL){
		header = (struct node*)malloc(sizeof(struct node));
		header->right = new_node;
		header->left = new_node;
		new_node->right = header;
	}
	else{
		new_node->right = header->right;
		new_node->left = header;
		header->right->left = new_node;
		header->right = new_node;
	}
	new_node->left = header;
	return header;
}

struct node* sum_of_cl(struct node* l1, struct node* l2){
	int digit_sum, carry=0;
	struct node *ptr1=l1, *ptr2=l2, *result=NULL;
	ptr1 = ptr1->left; ; ptr2 = ptr2->left;
	while(!(ptr1==l1 && ptr2==l2)){
		digit_sum = ptr1->digit + ptr2->digit + carry;
		carry = digit_sum / 10;
		digit_sum %= 10;
		result = add_node(result, digit_sum);
		ptr1 = ptr1->left; ptr2 = ptr2->left;
	}
	if(carry!=0)
		result = add_node(result, carry);
	return result;
}

void display(struct node* header){
	struct node* mark = header;
	header = header->right;
	while(header!=mark){
		printf("%d ", header->digit);
		header = header->right;
	}
	printf("\n");
}

int main(void){
	int choice, temp_digit;
	unsigned long int ele;
	struct node *num1=NULL, *num2=NULL, *sum=NULL;
	
	printf("Enter digits of first number\n");
	scanf("%ld", &ele);
	while(ele!=0){
		temp_digit = ele % 10;
		num1 = add_node(num1, temp_digit);
		ele /= 10;
	}
	printf("Linked List of num1 : ");
	display(num1);

	printf("Enter digits of second number\n");
	scanf("%ld", &ele);
	while(ele!=0){
		temp_digit = ele % 10;
		num2 = add_node(num2, temp_digit);
		ele /= 10;
	}
	printf("Linked List of num2 : ");
	display(num2);
	sum = sum_of_cl(num1, num2);
	display(sum);
}