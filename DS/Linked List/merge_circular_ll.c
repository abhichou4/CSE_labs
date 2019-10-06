#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node* link;
};

struct node* append_to_circular(struct node* header, char ele);
void display(struct node* header);
struct node* make_circular_ll(struct node* header);
struct node* merge_two_circulate(struct node* head1, struct node* head2);

int main(){
	struct node *clist1 = NULL, *clist2 = NULL, *merged=NULL;
	clist1 = make_circular_ll(clist1);
	clist2 = make_circular_ll(clist2);
	merged = merge_two_circulate(clist1, clist2);
	display(merged);
}

struct node* append_to_circular(struct node* header, char ele){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = ele;
	if(header!=NULL){
		struct node* lptr = header;
		int steps=0;
		while(steps < header->data) {
			lptr = lptr->link;
			steps++;
		}
		new_node->link = header;
		lptr->link = new_node;
	}
	else{
		header = (struct node*)malloc(sizeof(struct node));
		header->link = new_node;
		new_node->link = header;
		header->data = 0;
	}
	header->data++;
	return header;
}

void display(struct node* header){
	int steps = header->data; 
	header = header->link;
	while(steps>0){
		printf("%c  ", header->data);
		header = header->link;
		steps--;
	}
	printf("\n");
}

struct node* make_circular_ll(struct node* header){
	int choice; char ele, c;
    printf("---Making header linked list---\n");
    do{
        printf("1. Add elements\n2. Display queue\n");
        scanf("%d", &choice);
        switch(choice){

            case 1:
                printf("Enter element : ");
                scanf(" %c", &ele);
                header = append_to_circular(header, ele);
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

struct node* merge_two_circulate(struct node* head1, struct node* head2){
	struct node* result = NULL;
	int l1_len, l2_len, clist_len;
	l1_len = head1->data; l2_len = head2->data;
	clist_len = l1_len + l2_len;
	head1 = head1->link; head2 = head2->link;
	while(l1_len + l2_len > 0){
		if(l1_len==0){
			printf("HEAD1 == NULL\n");
			result = append_to_circular(result, head2->data);
			head2 = head2->link;
			l2_len--;
			display(result);
		}
		else if(l2_len==0){
			printf("HEAD2 == NULL\n");
			result = append_to_circular(result, head1->data);
			head1 = head1->link;
			l1_len--;
			display(result);
		}
		else if(head1->data < head2->data){
			printf("HEAD1 < HEAD2\n");
			result = append_to_circular(result, head1->data);
			head1 = head1->link;
			l1_len--;
			display(result);
		}
		else if(head1->data > head2->data){
			printf("HEAD2 < HEAD1\n");
			result = append_to_circular(result, head2->data);
			head2 = head2->link;
			l2_len--;
			display(result);
		}
		else{
			printf("HEAD1 == HEAD2\n");
			result = append_to_circular(result, head2->data);
			head1 = head1->link;
			head2 = head2->link;
			l1_len--; l2_len--;
			display(result);
		}
		clist_len--;
	}
	return result;
}