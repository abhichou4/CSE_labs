#include <stdio.h>

#define ARR_LEN 6

typedef struct{
	int arr[ARR_LEN];
	int front[2];
	int rear[2];
} double_queue;

int isFull(double_queue* q, int i){
	return((q->rear[i]+1)%(ARR_LEN/2)+i*(ARR_LEN/2)==q->front[i]);
}

int isEmpty(double_queue* q, int i){
	return(q->rear[i]==-1 && q->front[i]==-1);
}

void insertq(double_queue* q, int i, int ele){
	if(!isFull(q, i)){
		if(isEmpty(q,i)){
			q->front[i]=i*(ARR_LEN/2);
			q->rear[i]=i*(ARR_LEN/2);
			q->arr[q->rear[i]]=ele;
		}
		else{
			q->rear[i] = (q->rear[i]+1)%(ARR_LEN/2)+i*(ARR_LEN/2);
			q->arr[q->rear[i]]=ele;
		}
		printf("%d inserted at %d\n", ele, q->rear[i]);
	}
	else printf("Queue Full!\n");
}

int deleteq(double_queue* q, int i){
	if(!isEmpty(q, i)){
		int ele = q->arr[q->front[i]];
		printf("%d deleted form %d\n", ele, q->front[i]);
		if(q->front[i]==q->rear[i]){
			q->front[i]=-1;
			q->rear[i]=-1;
		}
		else{
			q->front[i] = (q->front[i]+1)%(ARR_LEN/2)+i*(ARR_LEN/2);
		}
		return ele;
	}
	else printf("Queue Empty!\n");
}

void display(double_queue* q){
	int i;
	printf("Queue 0:\n");
	i=q->front[0];
	do{
		printf("%d ", q->arr[i]);
		i=(i+1)%(ARR_LEN/2);
	} while(i!=q->rear[0]+1);
	printf("\n");
	printf("Queue 1:\n");
	i=q->front[1];
	do{
		printf("%d ", q->arr[i]);
		i=(i+1)%(ARR_LEN/2) + ARR_LEN/2;
	} while(i!=q->rear[1]+1);
	printf("\n");
}

int main(){

	double_queue q;
	q.front[0]=-1; q.rear[0]=-1;
	q.front[1]=-1; q.rear[1]=-1;

	insertq(&q, 0, 0);
	insertq(&q, 0, 1);

	insertq(&q, 1, 2);
	insertq(&q, 1, 3);

	display(&q);
}