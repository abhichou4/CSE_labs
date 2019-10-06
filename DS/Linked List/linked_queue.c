#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* link;
} Node;

void enqueue(Node** front, Node** rear, int ele){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = ele;
	temp->link = NULL;
	if(*front) (*rear)->link = temp;
	else *front = temp;  
	*rear = temp;
}

int dequeue(Node** front, Node** rear){
	Node* temp = *front;
	if(temp==NULL){
		printf("Queue Empty!\n");
	}
	else{
		int ele = temp->data;
		*front = temp->link;
		free(temp);
		return ele;
	}
}

void display(Node* front, Node* rear){
	Node* trav= front;
	while(trav!=NULL){
		printf("%d  ", trav->data);
		trav = trav->link;
	}
	printf("\n");
}

int main(void){
	int choice; char c;
	Node* front=NULL;
	Node* rear=NULL;
	do{
		printf("Enter action to perform\n1. Enqueue\n2. Dequeue\n3. Display\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter element\n"); int ele;
				scanf("%d", &ele);
				enqueue(&front, &rear, ele); 
				break;
			case 2:
				ele = dequeue(&front, &rear);
				break;
			case 3:
				display(front, rear);
				break;
			default:
				printf("Enter valid option\n");
		}
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y'|c=='Y');
}