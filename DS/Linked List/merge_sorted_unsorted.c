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

//utility to find position to insert
struct node* posInsert(struct node* sorted, int ele){
	while(sorted->next!=NULL){
		if(sorted->next->data > ele)
			return sorted; 
		sorted = sorted->next;
	}
	return sorted;
}

//merding an unsorted linked-list into a sorted linked-list
struct node* merge_sorted_unsorted(struct node* sorted, struct node* unsorted){
	struct node* sorted_first = sorted;
	while(unsorted!=NULL){
		struct node* tail = posInsert(sorted, unsorted->data);
		struct node* new_node = make_node(unsorted->data);
		new_node->next = tail->next;
		tail->next = new_node;
		unsorted = unsorted->next;
	}
	return sorted_first;
}

int main(void){
	struct node *l1 = NULL, *l2=NULL; 
	l1 = make_ll(l1);
	l2 = make_ll(l2);
	struct node* res = merge_sorted_unsorted(l1, l2);
	display(res);
}