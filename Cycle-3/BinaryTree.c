#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

node* create(int data){
    node *newNode = malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

node *insertLeft(node *root, int data){
    root->left = create(data);
    return root->left;
}

node *insertRight(node *root, int data){
    root->right = create(data);
    return root->right;
}

void inorder(node *root){
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

void preorder(node *root){
    if (root == NULL)
        return;
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}

void main(){
    int ch, elt;
    node *root = NULL;
    do{
        printf("\nMENU");
        printf("\n1. Create root\n2. Insert Left Child\n3. Insert Right Child\n4. Inorder\n5. Preorder\n6. Postorder\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter element: ");
                scanf("%d",&elt);
                root = create(elt);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d",&elt);
                insertLeft(root,elt);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d",&elt);
                insertRight(root,elt);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                preorder(root);
                break;
            case 6:
                postorder(root);
                break;
        }
    } while (ch<7);
}