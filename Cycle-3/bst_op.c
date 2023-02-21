#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data){
    if (root == NULL)
        root = createNode(data);
    else if (root->data >= data)
        root->left = insertNode(root->left,data);
    else
        root->right = insertNode(root->right,data);
    return root;
}

bool searchNode(struct Node* root, int data){
    if (root == NULL)
        return false;
    if (root->data = data)
        return true;
    else if(data <= root->data)
        return searchNode(root->left,data);
    else
        return searchNode(root->right,data);
}

struct Node *FindMinimum(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int data){
    if (root == NULL)
        return root;
    else if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right,data);
    else{
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if (root->left == NULL || root->right == NULL){
            struct Node *temp = root;
            if (root->left){
                root = root->left;
            }
            else{
                root = root->right;
            }
            free(temp);
        }
        else{
            struct Node *temp = findMinimun(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }

}

