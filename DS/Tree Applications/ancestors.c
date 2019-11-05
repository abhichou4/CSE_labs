#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right, *left;
};

struct node* make_node(int ele){
  struct node* new_node = (struct node*)malloc(sizeof(struct node*));
  new_node->data=ele;
  new_node->right=NULL;
  new_node->left=NULL;
  return new_node;
}

void create_bt_recursive(struct node** root, int ele){
    if(*root==NULL)
        *root = make_node(ele);
    else{
        char c;
        printf("left or right of %d", (*root)->data);
        scanf(" %c", &c);
        if(c=='l')
            create_bt_recursive(&(*root)->left, ele);
        else 
            create_bt_recursive(&(*root)->right, ele);
    }
}

int ancestors(struct node* root, int ele){
    if(root->data==ele)
        return 1;
    else if(root==NULL)
        return 0;
    else{
        if(root->left!=NULL){
		if(ancestors(root->left, ele)){
		    printf("%d  ", root->data);
		    return 1;    
		}
	}
	if(root->right!=NULL){
        if(ancestors(root->right, ele)){
            printf("%d  ", root->data);
            return 1;
        }
	}
	return 0;
     }
}       
void main(void){
    struct node* root = NULL;
    int ele; char c;
    do{
        printf("Enter Data\n");
        scanf("%d", &ele);
        create_bt_recursive(&root, ele);
        printf("Continue? y or n\n");
        scanf(" %c", &c);
    } while(c=='y'||c=='Y');
    printf("Ancestor of?\n");
    int tmp;
    scanf("%d", &tmp);
    int temp = ancestors(root, tmp);
    printf("\n");
}
