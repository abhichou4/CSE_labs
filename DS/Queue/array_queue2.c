#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int rear, front;
	unsigned size, capacity;
	int* arr;
} queue;

int isFull(queue* Queue){
	return( Queue -> size == Queue -> capacity);
}

int isEmpty(queue* Queue){
	return( Queue -> size == 0);
}

queue* makeQueue(unsigned capacity){

	queue* new_queue;
	new_queue = (queue*)malloc(sizeof(queue));
	new_queue->arr = (int*)calloc(capacity, sizeof(int));
	new_queue->rear = capacity -1; new_queue->front = 0;
	new_queue -> capacity = capacity;
	new_queue -> size = 0;
	return new_queue;
}

void enqueue(queue* Queue, int element){
	if(isFull(Queue)){
		printf("Queue FULL!\n");
		return;
	}

	Queue -> rear = (Queue -> rear + 1) % Queue -> capacity;
	Queue -> arr[Queue->rear] = element;
	(Queue -> size)++;
	printf("Enqueued element %d at index %d\n", element, Queue->rear);
}

void dequeue(queue* Queue){
	if(isEmpty(Queue)){
		printf("Queue EMPTY!\n");
		return;
	}

	printf("Dequeued element %d at index %d\n", Queue->arr[Queue->front], Queue->front);
	Queue -> front = (Queue -> front + 1) % Queue -> capacity;
	Queue -> size = Queue -> size -1;
}

int main(void){
	
	queue* q;
	q = makeQueue(3);
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	dequeue(q);
	return 0;
}