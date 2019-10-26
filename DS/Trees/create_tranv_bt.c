#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define true 1
#define false 0

struct node{
	int data;
	struct node *left, *right;
};

//linked-list queue implementation

struct ll_node{
	struct node* data;
	struct ll_node* link;
};

void enqueue(struct ll_node** front, struct ll_node** rear, struct node* node){
	struct ll_node* temp = (struct ll_node*)malloc(sizeof(struct ll_node));
	temp->data = node;
	temp->link = NULL;
	if(*front==NULL)
		*front = temp;
	else 
		 (*rear)->link = temp;
	*rear = temp;
}

struct node* dequeue(struct ll_node** front, struct ll_node** rear){
	struct ll_node* temp = *front;
	if(temp==NULL){
		printf("Queue Empty!\n");
		return NULL;
	}
	else{
		struct node* node = temp->data;
		*front = temp->link;
		free(temp);
		return node;
	}
}

void display_q(struct ll_node* front, struct ll_node* rear){
	do{
		printf("%d  ", front->data->data);
		front = front->link;
	}while(front!=NULL);
}

//array stack implementation

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
	else printf("Stack Overflow\n");
}

struct node* pop(stack* s){
	if(!isEmpty(s)) {
		struct node* node = s->arr[(s->top)--]; 
		//printf("%d popped from stack at %d\n", node->data, (s->top)+1);
		return node;
	}
	else{ 
		printf("Stack Underflow\n");
		return NULL;
	}
}

void display(stack* s){
	if(s->top==-1){
		printf("Stack is empty.\n");
	}
	int i=0;
	while(i<=s->top){
		printf("%d  ", (s->arr[i++])->data);
	}
	printf("\n");
}

//create and transverse trees 
//iterative and recursive implementations

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

void create_tree_recursive(struct node** root){
	int ele;
	if(*root==NULL){
		printf("Enter element\n");
		scanf("%d", &ele);
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->data = ele;
		(*root)->right=NULL;
		(*root)->left=NULL;
		return;
	}
	printf("Enter to left or right of %d\n", (*root)->data);
	char* choice;
	scanf("%ms", &choice);
	if(!strcmp(choice, "left")){
		create_tree_recursive(&(*root)->left);
	}
	else
		create_tree_recursive(&(*root)->right);
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

void preorder_recursive(struct node* root){
	if(root!=NULL){
		printf("%d  ", root->data);
		preorder_recursive(root->left);
		preorder_recursive(root->right);
	}
	else
		return;
}

void postorder_recursive(struct node* root){
	if(root!=NULL){
		postorder_recursive(root->left);
		postorder_recursive(root->right);
		printf("%d  ", root->data);
	}
	else
		return;
}

void inorder_iterative(struct node* root){
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

void preorder_iterative(struct node* root){
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
		printf("%d  ", node->data);
	}
}

void postorder_iterative_1stack(struct node* root){
	if(root==NULL){
		printf("Tree is Empty\n");
		return;
	}
	stack s;
	s.top=-1;
	struct node* temp_right = NULL;
	do{
		if(root!=NULL){
			if(root->right!=NULL)
				push(&s, root->right);
			push(&s, root);
			root = root->left;
		}
		else{
			root = pop(&s);
			//isEmpty case so it doesn't give seg-fault for s.arr[s.top] as s.top=-1 in the end
			if(isEmpty(&s)){
				printf("%d  ", root->data);
				return;
			}
			if(root->right!=NULL && s.arr[s.top]==root->right){
				temp_right = pop(&s);
				push(&s, root);
				root = temp_right;
			}
			else{
				printf("%d  ", root->data);
				root=NULL; 	
			}
		}
	} while(!isEmpty(&s));
}

void levelOrder_iterative(struct node* root){
	if(root==NULL){
		printf("Tree is empty\n");
		return;
	}
	struct ll_node* front = NULL;
	struct ll_node* rear = NULL;
	enqueue(&front, &rear, root);
	while(front!=NULL){
		struct node* root = dequeue(&front, &rear);
		printf("%d  ", root->data);
		if(root->left!=NULL)
			enqueue(&front, &rear, root->left);
		if(root->right!=NULL)
			enqueue(&front, &rear, root->right);
	}
}

void printLevel(struct node* root, int level){
	if(level==0)
		printf("%d  ", root->data);
	if(level>=1){
		if(root->left!=NULL)
			printLevel(root->left, level-1);
		if(root->right!=NULL)
			printLevel(root->right, level-1);
	}
}

int findHeight(struct node* root){
	if(root==NULL){
		return 0;
	}
	else{
		int left_subtree_h = 1 + findHeight(root->left);
		int right_subtree_h = 1 + findHeight(root->right);
		return(left_subtree_h > right_subtree_h ? left_subtree_h : right_subtree_h);
	}
}

void levelOrder_NoQueue(struct node* root){
	int h = findHeight(root);
	for(int i=0; i<h; i++){
		printLevel(root,i);
	}
}

int main(void){
	struct node* root = NULL;
	char c;
	do{
		create_tree_recursive(&root);
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y'||c=='Y');
	printf("Inorder:\n");
	inorder_recursive(root);
	printf("\n");
	inorder_iterative(root);
	printf("\n");
	printf("Preorder\n");
	preorder_recursive(root);
	printf("\n");
	preorder_iterative(root);
	printf("\n");
	printf("Postorder\n");
	postorder_recursive(root);
	printf("\n");
	postorder_iterative_1stack(root);
	printf("\n");
	postorder_iterative_2stack(root);
	printf("\n");
	printf("Levelorder:\n");
	levelOrder_iterative(root);
	printf("\n");
	levelOrder_NoQueue(root);
	printf("\n");
}