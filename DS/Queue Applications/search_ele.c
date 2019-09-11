#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN 3

typedef struct{
	int arr[ARR_LEN];
	int front;
	int rear;
} queue;

int isFull(queue* q){
	return((q->rear+1)%ARR_LEN==q->front);
}

int isEmpty(queue* q){
	return(q->rear==-1 && q->front==-1);
}

void insertq(queue* q, int ele){
	if(!isFull(q)){
		if(isEmpty(q)){
			q->front=0;
			q->rear=0;
			q->arr[q->rear]=ele;
		}
		else{
			q->rear = (q->rear+1)%ARR_LEN;
			q->arr[q->rear]=ele;
		}
		printf("%d inserted at %d\n", ele, q->rear);
	}
	else printf("Queue Full!\n");
}

int deleteq(queue* q){
	if(!isEmpty(q)){
		int ele = q->arr[q->front];
		printf("%d deleted form %d\n", ele, q->front);
		if(q->front==q->rear){
			q->front=-1;
			q->rear=-1;
		}
		else{
			q->front = (q->front+1)%ARR_LEN;
		}
		return ele;
	}
	else printf("Queue Empty!\n");
}

int isPresent(queue* q, int ele){
	int flag=0, i, temp;
	i = q->rear;
	do{
		if(q->arr[q->front]==ele){
			flag=1;
		}
		temp = deleteq(q);
		insertq(q, temp);
	} while(q->front!=(i+1)%ARR_LEN);
	return flag;
}

int main(void){

	queue q; q.front = -1; q.rear = -1;
	int choice; char c;

	do{
		
		printf("Enter action to perform\n1. Insert\n2. Delete\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter element to Insert\n");
				int ele;
				scanf("%d", &ele);
				insertq(&q, ele);
				break;

			case 2:
				deleteq(&q);
				break;

			default:
				printf("Enter valid option\n");
		}
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while (c=='y' || c=='Y');
	int ele;
	printf("Enter element to check\n");
	scanf("%d", &ele);
	if(isPresent(&q, ele)) printf("True\n");
	else printf("False\n");
}