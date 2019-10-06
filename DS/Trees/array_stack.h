#define MAX_LEN 100
#define true 1
#define false 0

struct node{
	int data;
	struct node *right, *left;
};

typedef struct{
	struct node* arr[MAX_LEN];
	int top;
} stack;

int isFull(stack* s);
int isEmpty(stack *s);
void push(stack* s, struct node* node);
struct node* pop(stack* s);
void display(stack* s);
void rev_display(stack* s);

