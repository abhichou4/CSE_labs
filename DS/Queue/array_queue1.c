#include <stdio.h>

#define MAX_QUEUE_LENGTH 3

typedef struct{
	int value1;
	int value2;
} element;

void queueFull(void){
	printf("Queue FULL!\n");
}

void queueEmpty(void){
	printf("Queue EMPTY!\n");
}

void enqueue(element arr[], element e, int* front, int* rear){
	
	int temp = ((*rear)+1) % MAX_QUEUE_LENGTH;

	if(*front == temp){
		queueFull();
		return;
	}

	arr[temp] = e;
	*rear = temp;
	printf("Enqueued element at %d\n", *rear);
}

element dequeue(element arr[], int* front, int* rear){

	*front = ((*front)+1) % MAX_QUEUE_LENGTH;	

	if(front == rear){
		queueEmpty();
	}

	element e = arr[*front];

	printf("Dequeued element at front\n");

	return e;
}

int main(void){

	element arr[3];
	int front=0, rear=0, c;
	
	while(1){
		printf("1. Enter element.\n2. Delete element\n");
		scanf("%d", &c);

		switch(c){
			case 1: ;
			element e;
			printf("Enter value1 and value2\n");
			scanf("%d %d", &e.value1, &e.value2);
			enqueue(arr, e, &front, &rear);
			break;

			case 2:
			dequeue(arr, &front, &rear);
			break;
		}
	}

	return 0;
}