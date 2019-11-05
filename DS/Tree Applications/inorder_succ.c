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

void create_bst_recursive(struct node** root, int ele){
  if(*root==NULL){
    *root=make_node(ele);
  }
  else{
    if(ele>(*root)->data)
        create_bst_recursive(&(*root)->right, ele);
    else if(ele<(*root)->data)
        create_bst_recursive(&(*root)->left, ele);
    else 
        return;    
  }
  return;
}

struct node* find_node(struct node* root, int ele){
    if(root->data==ele){
        return root;
    }
    else{
        if(ele<root->data && root->left!=NULL)
            find_node(root->left, ele);
        else
            find_node(root->right, ele);
    }
}

struct node* inorder_succ(struct node* root, int ele){
    struct node* ptr = find_node(root, ele);
    if(ptr->right!=NULL){
        ptr = ptr->right;
        while(ptr->left!=NULL)
                ptr = ptr->left;
    }
    return ptr;
}
         
void inorder_recursive(struct node* root){
    if(root!=NULL){
        inorder_recursive(root->left);
        printf("%d  ", root->data);
        inorder_recursive(root->right);
    }
    else
        return;
}

void main(void){
    struct node* root = NULL;
    char c; int ele, t;
    do{
        printf("Enter Data\n");
        scanf("%d", &ele);
        create_bst_recursive(&root, ele);
        printf("Continue? y or n\n");
        scanf(" %c", &c);
    } while(c=='y' || c=='Y');
    printf("Inorder successor of?\n");
    scanf("%d", &t);
    struct node* temp = inorder_succ(root, t);
    printf("%d", temp->data);
}
