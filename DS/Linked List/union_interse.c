#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* append_node(struct node* header, int ele);
void display(struct node* header);
struct node* create_copy(struct node* header);
struct node* create_hll(struct node* header);
struct node* set_union(struct node* s1, struct node* s2);
struct node* set_intersection(struct node* s1, struct node* s2);

int main(){
    struct node *set1 = NULL, *set2 = NULL; 
    set1 = create_hll(set1);
    set2 = create_hll(set2);
    struct node *union_set, *intersection_set;
    union_set = set_union(set1, set2);
    intersection_set = set_intersection(set1, set2);
    display(union_set);
    display(intersection_set);

}

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

struct node* create_copy(struct node* header){
    struct node* copy = (struct node*)malloc(sizeof(struct node));
    copy->link = NULL;
    header = header->link;
    while(header!=NULL){
        copy = append_node(copy, header->data);
        header = header->link;
    }
    return copy;
}

int isPresent(struct node* header, int ele){
    header = header->link;
    int flag=0;
    while(header!=NULL){
        if(header->data==ele) 
            flag=1;
        header = header->link;
    }
    return flag;
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

struct node* set_union(struct node* s1, struct node* s2){
    struct node *result = NULL;
    struct node *smaller_set = NULL, *larger_set=NULL;
    if(s2->data < s1->data){
        smaller_set = s2;
        larger_set = s1; 
    }
    else{
        smaller_set = s1;
        larger_set = s2;
    }
    result = create_copy(larger_set);

    smaller_set = smaller_set->link;
    while(smaller_set!=NULL){
        if(!isPresent(result, smaller_set->data)) 
            result = append_node(result, smaller_set->data);
        smaller_set = smaller_set->link;
    }
    return result;
}

struct node* set_intersection(struct node* s1, struct node* s2){
    struct node* result = NULL;
    struct node *smaller_set = NULL, *larger_set=NULL;
    if(s2->data < s1->data){
        smaller_set = s2;
        larger_set = s1; 
    }
    else{
        smaller_set = s1;
        larger_set = s2;
    }
    smaller_set = smaller_set->link;
    while(smaller_set!=NULL){
        if(isPresent(larger_set, smaller_set->data)){
            result = append_node(result, smaller_set->data);
        }
        smaller_set = smaller_set->link;
    }
    return result;
}