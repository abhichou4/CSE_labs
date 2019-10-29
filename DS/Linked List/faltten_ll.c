#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
	struct node* right;
};

struct node* make_node(int data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->right=NULL;
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

        printf("Go right? y or n\n");
        scanf(" %c", &c);
    } while(c=='n' | c=='n');

    return first;
}

struct node* make_ragged_ll(struct node* first_main){
	char c; 
	do{
		struct node* new_ll = NULL;
		new_ll = make_ll(new_ll);
		if(first_main==NULL){
			first_main = new_ll;
			printf("FIRST LL ADDED\n");
		}
		else{
			struct node* trav = first_main;
			while(trav->right!=NULL)
				trav = trav->right;
			trav->right = new_ll;
			printf("NEW LL ADDED\n");
		}
		printf("Continue? y or n\n");
		scanf(" %c", &c);
	} while(c=='y' || c=='Y');
	return first_main;
}

void display_all(struct node* first_main){
	while(first_main!=NULL){
		display(first_main);
		printf("\n");
		first_main = first_main->right;
	}
}

struct node* flatten(struct node* first_main){
	struct node* trav = first_main;
	while(trav){
		struct node* indiv_ll = trav;
		struct node* next_ll = trav->right;
		while(indiv_ll->next!=NULL){
			indiv_ll->right = indiv_ll->next;
			indiv_ll->next = NULL;
			indiv_ll = indiv_ll->right;
		}
		indiv_ll->right = next_ll;
		trav = next_ll;
	}
	return first_main;
}

int main(void){
	struct node* r_ll = NULL;
	r_ll = make_ragged_ll(r_ll);
	printf("Ragged linked-list\n");
	display_all(r_ll);
	struct node* fl = flatten(r_ll);
	printf("Flattened linked-list\n");
	display_all(fl);
}