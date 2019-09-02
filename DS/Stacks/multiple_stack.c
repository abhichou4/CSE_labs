#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 100
#define NO_STACK 10
 /* 

k=3 Stack in an array of length 6

Represents top of the k stacks 	-> topOfStack = {-1, -1, -1} 
The array we divide				-> stackData = {0, 0, 0, 0, 0, 0}

#tricky
When not-set: Index of next availble in array
When set: the PREVIOUS topOfSatck so we know how to pop -> nextIndex = {1, 2, 3, 4, 5, -1}

Where to add any next element to -> nextAvailable = 0

------ DRY RUN ------

topOfStack = {-1, -1, -1}
stackData = {0, 0, 0, 0, 0, 0} 
nextIndex = {1, 2, 3, 4, 5, -1}
nextAvailable = 0

push(0,	5)
#look at nextAvailable
stackData = {5, 0, 0, 0, 0, 0}
#set nextIndex and previous topOfStack 
topOfStack[0]=-1 -> nextIndex = {-1, 2, 3, 4, 5, -1}
#change topOfStack to nextAvaiable
nextAvailable=0 -> topOfStack = {0, -1, -1}
#change nextAvailable to nextIndex[0]
undo-nextIndex[1] -> nextAvailable = 1

push(0, 6)
#look at nextAvailable 
stackData = {5, 6, 0, 0, 0, 0}
#set nextIndex and previous topOfStack 
topOfStack[0]=0 -> nextIndex = {-1, 0, 3, 4, 5, -1}
#change topOfStack to nextAvaiable
nextAvailable=1 -> topOfStack = {1, -1, -1}
#change nextAvailable to nextIndex[0]
undonextIndex[2] -> nextAvailable = 2

push(7, 1)
#look at nextAvailable
setData = {5, 6, 7, 0, 0, 0}
#set nextIndex to previous topStack
nextIndex = {-1, 0, -1, 4, 5, -1}
#set topOfStack to nextAvailable 
nextAvailable = 2 -> topOfStack = {1, 2, -1}
#set nextAvailable to previous nextIndex
undonextIndex[3] -> nextAvailable = 3

*/

typedef struct{
	int* stackData;
	int* topOfStack;
	int* nextIndex;
	int nextAvailable;
} k_stacks;

k_stacks* make_stack(void){
	k_stacks* s = (k_stacks*)malloc(sizeof(k_stacks));
	s->stackData = (int*)malloc(ARR_LEN*sizeof(int));
	s->topOfStack = (int*)malloc(NO_STACK*sizeof(int));
	s->nextIndex = (int*)malloc(ARR_LEN*sizeof(int));
	s->nextAvailable = 0;

	int i;
	for(i=0; i<ARR_LEN; i++){
		s->stackData[i] = 0;
		s->nextIndex[i] = i+1;
	}
	s->nextIndex[ARR_LEN-1] = -1;

	for(i=0; i<NO_STACK; i++){
		s->topOfStack[i] = -1;
	}

	printf("Array of length %d with %d stacks\n", ARR_LEN, NO_STACK);

	return s;
}

int isFull(k_stacks* s){
	return(s->nextAvailable==-1);
}

int isEmpty(k_stacks* s, int i){
	return(s->topOfStack[i]==-1);
}

void push(k_stacks* s, int i, int value){

	if (isFull(s)) return;

	int currentIndex = s->nextAvailable;
	s->stackData[currentIndex] = value;
	s->nextAvailable = s->nextIndex[currentIndex];
	s->nextIndex[currentIndex] = s->topOfStack[i];
	s->topOfStack[i] = currentIndex;
	printf("%d added at %d of array\n", value, currentIndex);
}

void pop(k_stacks* s, int i){

	if(isEmpty(s, i)) {printf("Stack Underflow!\n"); return;}

	int currentIndex = s->topOfStack[i];
	int value = s->stackData[currentIndex];
	s->topOfStack[i] = s->nextIndex[currentIndex];
	s->nextIndex[currentIndex] = s->nextAvailable;
	s->nextAvailable = currentIndex;
	printf("%d removed from %d  of array\n", value, currentIndex);
}

void peek(k_stacks* s, int i){
	int value = s->stackData[s->topOfStack[i]];
	printf("%d is at top of %d stack\n", value, i);
}

int main(void){

	k_stacks* stk;
	stk = make_stack();
	int i, value; char ch;

	do{
		printf("Enter action to perform\n1.Push\n2.Pop\n3.Peek\n");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter stack number and element to push\n");
				scanf("%d", &i);
				scanf("%d", &value);
				push(stk, i, value);
				break;

			case 2:
				printf("Enter stack to pop from\n");
				scanf("%d", &i);
				pop(stk, i);
				break;

			case 3:
				printf("Enter stack to peek\n");
				scanf("%d", &i);
				peek(stk, i);
				break;
		}

		printf("Continue? y or n\n");
		scanf(" %c", &ch);
	} while (ch=='y' || ch =='Y');
}