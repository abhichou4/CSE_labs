#define true 1
#define false 0

typedef struct{
	char* arr;
	int top;
	unsigned capacity;
} stack;

stack* make_stack(int size);
int isFull(stack* s);
int isEmpty(stack *s);
void push(stack* s, char ele);
char pop(stack* s);
char peek(stack* s);
void display(stack* s);
void rev_display(stack* s);


