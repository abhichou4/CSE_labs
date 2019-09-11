#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 3
#define STRING_SIZE 10	

typedef struct{
	char** arr;
	int front;
	int rear;
} queue;

queue* make_queue(){
	queue* q = (queue*)malloc(sizeof(queue));
	q->arr = (char**)malloc(QUEUE_SIZE);
	for(int i=0; i<QUEUE_SIZE; i++){
		q->arr[i] = (char*)malloc(STRING_SIZE);
	}
	q->front = -1;
	q->rear = -1;
	return q;
}

int isEmpty(queue* q){
	return(q->front==-1 && q->rear==-1);
}

int isFull(queue* q){
	return((q->rear+1)%QUEUE_SIZE==q->front);
}

void insertcq(queue* q, char* str){
	if(!isFull(q)){
		if(isEmpty(q)){
			q->front=0;
			q->rear=0;
			strcpy(q->arr[q->rear], str);
		}
		else{
			q->rear = (q->rear + 1)%QUEUE_SIZE;
			strcpy(q->arr[q->rear], str);
		}
		printf("%s added at %d\n", str, q->rear);
	}
	else printf("Queue Full!\n");
}

char* deletecq(queue* q){
	char* ch = q->arr[q->front];
	if(!isEmpty(q)){
		printf("%s deleted from %d\n", ch, q->front);
		if(q->front==q->rear){
			q->front = -1;
			q->rear = -1;
		}
		else q->front = (q->front +1)%QUEUE_SIZE;
		return ch;
	}
	else printf("Queue Empty!\n");
}

void displaycq(queue* q){
	int i = q->front;
	do{
		printf("%s\n", q->arr[i]);
		i=(i+1)%QUEUE_SIZE;
	} while(i!=q->rear+1);
}

int main(void){

	int choice; 
	char* ch;
	queue* q = make_queue();
	char c;
	do{
		printf("Enter action to peform\n1. Insert string\n2. Delete string\n3. Display queue\n");
		scanf("%d", &choice);
		switch(choice){

			case 1:
				printf("Enter string to add\n");
				char* str;
				scanf("%ms", &str);
				insertcq(q, str);
				break;

			case 2:
				ch = deletecq(q);
				break;

			case 3:
				displaycq(q);
				break;

			default:
				printf("Enter valid option\n");
		}
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y' || c=='Y');
}