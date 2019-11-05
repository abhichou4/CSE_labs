#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right, *left;
};

struct node* make_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->right = new_node->left = NULL;
    return new_node;
}

struct node* create_bt_iterative(struct node* root, int ele){
    char c;
    if(root==NULL)
        root = make_node(ele);
    else{
        struct node* trav = root;
        while(1){
            printf("Left of right of %d\n", trav->data);
            scanf(" %c", &c);
            if(c=='l'){
                if(trav->left==NULL){
                    trav->left = make_node(ele);
                    break;
                }
                else 
                    trav = trav->left;
            }
            else {
                if(trav->right==NULL){
                    trav->right = make_node(ele);
                    break;
                }
                else 
                    trav = trav->right;
            }
        }
    }
    return root;
}

int height_of_bt(struct node* root){
    if(root==NULL)
        return 0;
    else{
        int k = (height_of_bt(root->left)>=height_of_bt(root->right))?height_of_bt(root->left):height_of_bt(root->right);
        int height = 1 + k;
        return height;
    }
}

int no_of_leaves(struct node* root){
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return no_of_leaves(root->left) + no_of_leaves(root->right);
}

int no_of_nodes(struct node* root){
    if(root==NULL)
        return 0;
    else
        return (1 + no_of_nodes(root->left) + no_of_nodes(root->right));
}

int main(void){
    struct node* root = NULL;
    int ele; char c;
    do{
        printf("Enter Data\n");
        scanf("%d", &ele);
        root = create_bt_iterative(root, ele);
        printf("Continue? y or n\n");
        scanf(" %c", &c);
    } while(c=='y' || c=='Y');

    printf("Height : %d\n", height_of_bt(root));
    printf("No. of Leaf Nodes : %d\n", no_of_leaves(root));
    printf("No. of Nodes : %d\n", no_of_nodes(root));
}