#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* make_node(int data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

struct node* append_node(struct node* first, int data){
	struct node* new_node = make_node(data);
	if(first==NULL){
		first = new_node;
		return first;
	}
	struct node* trav = first;
	while(trav->next!=NULL)
		trav = trav->next;
	trav->next = new_node;
	return first;
}

void display(struct node* first){
	while(first){
		printf("%d  ", first->data);
		first = first->next;
	}
}

struct node* make_ll(struct node* first){
	int choice; int ele; char c;
    printf("---Making linked list---\n");
    do{
        printf("1. Add elements\n2. Display List\n");
        scanf("%d", &choice);
        switch(choice){

            case 1:
                printf("Enter element : ");
                scanf("%d", &ele);
                first = append_node(first, ele);
                break;

            case 2:
                display(first);
                break;

            default:
                printf("Enter valid option\n");
        }

        printf("Continue? y or n\n");
        scanf(" %c", &c);
    } while(c=='y' | c=='Y');

    return first;
}

struct node* middle_ele(struct node* first){
	struct node *slow = first;
	struct node *fast = first;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main(void){
	struct node* first = NULL;
	first = make_ll(first);

	struct node* mid = middle_ele(first);
	printf("%d\n", mid->data);
}