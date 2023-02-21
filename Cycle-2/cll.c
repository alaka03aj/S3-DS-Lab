#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void insertFront(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (last == NULL)
        last = newNode;
    else
        newNode->next = last->next;
    last->next = newNode;
}

void insertEnd(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (last == NULL)
        last = newNode;
    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void insertAfter(int pos, int data){
    if (last == NULL){
        printf("List empty\n");
        return;
    }
    
        struct Node *curr = last->next;
        while (--pos)
            {
                curr = curr->next;
                if (curr == last->next)
                {
                    printf("\nPosition exceeded list size");
                    return;
                }
        }
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = curr->next;
    curr->next = newNode;
    if (curr == last)
        last = newNode;
}