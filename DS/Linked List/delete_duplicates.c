#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* append_node(struct node* header, int ele){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->link = NULL;
    if(header!=NULL){
        struct node* lptr = header;
        while(lptr->link!=NULL) lptr = lptr->link;
        lptr->link = new_node;
    }
    else{
        header = (struct node*)malloc(sizeof(struct node));
        header->data=0;
        header->link = new_node;
    }
    header->data++;
    return header;
}

void display(struct node* header){
    printf("Number of elements : %d\n", header->data);
    header = header->link;
    while(header!=NULL){
        printf("%d ", header->data);
        header = header->link;
    }
    printf("\n");
}

struct node* create_hll(struct node* header){
    int ele, choice; char c;
    printf("---Making header linked list---\n");
    do{
        printf("1. Add elements\n2. Display queue\n");
        scanf("%d", &choice);
        switch(choice){

            case 1:
                printf("Enter element : ");
                scanf("%d", &ele);
                header = append_node(header, ele);
                break;

            case 2:
                display(header);
                break;

            default:
                printf("Enter valid option\n");
        }

        printf("Continue? y or n\n");
        scanf(" %c", &c);
    } while(c=='y' | c=='Y');

    return header;
}

struct node* delete_node(struct node* header, struct node* trail){
	struct node* temp = trail->link;
	trail->link = trail->link->link;
	free(temp);
	header->data--;
	return header;
}

struct node* delete_duplicates(struct node* header){
	struct node* ptr = header;
	if(ptr==NULL) printf("List is Empty\n");
	else{
		ptr = ptr->link;
		while(ptr->link!=NULL){
			if(ptr->data==ptr->link->data){
				header = delete_node(header, ptr);
			}
			else ptr = ptr->link;
		}
	}
	return header;
}

int main(){
	struct node* list = NULL;
	list = create_hll(list);
	list = delete_duplicates(list);
	display(list);
}