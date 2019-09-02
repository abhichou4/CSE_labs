#define MAX_LEN 100
#define true 1
#define false 0

typedef struct{
	char arr[MAX_LEN];
	int top;
} stack;

int isFull(stack* s);
int isEmpty(stack *s);
void push(stack* s, int ele);
void pop(stack* s);
void display(stack* s);
void rev_display(stack* s);

