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

struct node* reverse_ll(struct node* first){
	struct node *current=first->next, *trail=first, *succ=first->next->next;
	while(succ!=NULL){
		current->next = trail;
		trail->next = NULL;
		trail = current;
		current = succ;
		succ = succ->next;
	}
	current->next = trail;
	first = current;
	return first;
}

struct node* add_one(struct node* first){
	struct node* rev = reverse_ll(first); 
	int carry=1, sum;
	struct node* trav = rev;
	while(trav!=NULL){
		sum = trav->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		trav->data = sum;
		trav = trav->next;
	}
	if(carry>0)
		append_node(rev, 1);
	return reverse_ll(rev);
}

int main(void){
	struct node* first = NULL;
	first= make_ll(first);
	first = add_one(first);
	display(first);
}