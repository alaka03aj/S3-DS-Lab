#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertFront(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void insertBack(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL){
        head = newNode;
    }
    else{
        struct Node *ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void insertAt(int pos, int data){
    int found = 0;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL){
        found = 0;
    }
    else{
        int count=0;
        struct Node *ptr = head;
        while(ptr!=NULL){
            count++;
            if (count== pos-1){
                found = 1;
                struct Node *temp = ptr->next;
                newNode->data = data;
                ptr->next = newNode;
                newNode->next = temp;
                break;
            }
            else
                ptr = ptr->next;
        }
    }
    if (found == 0){
        printf("\nNo such position available");
    }
}

void deleteFront(){
    struct Node *temp;
    if (head == NULL)
        printf("Empty list\n");
    else{
        temp = head;
        printf("Deleted: %d",temp->data);
        head = head->next;
        free(temp);
    }
}

void deleteBack(){
    struct Node *temp, *ptr;
    if (head == NULL)
        printf("List empty\n");
    else{
        ptr = head;
        while (ptr->next!=NULL){
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
    }
}

void deleteAt(int pos){
    struct Node *temp, *ptr;
    int found = 0, count = 0;
    ptr = head;
    if (head == NULL)
        found = 0;
    else{
        if (pos == 1){
            found = 1;
            temp = head;
            head = head->next;
            printf("\nDeleted: %d",temp->data);
            free(temp);
        }
        else{
            count = 1;
            while (ptr!=NULL && count<pos){
                temp = ptr;
                ptr = ptr->next;
                count++;
            }
            if (ptr == NULL){
                found = 0;
            }
            else{
                found = 1;
                temp->next = ptr->next;
                printf("Deleted: %d",ptr->data);
                free(ptr);
            }
        }
    }
    if (found == 0)
        printf("\nNo such position found!");
}

void display(){
    struct Node *ptr = head;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("X\n");
}

struct Node* reverse(){
    struct Node *next = NULL, *prev = NULL;
    struct Node *curr = head;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    int ch, element, pos;
    struct Node *newHead, *curr;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Insert at beginning");
        printf("\n2.Insert at end");
        printf("\n3.Insert at position");
        printf("\n4.Delete from front");
        printf("\n5.Delete from back");
        printf("\n6.Delete from a position");
        printf("\n7.Display linked list");
        printf("\n8.Reverse");

        printf("\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertFront(element);
            break;
        case 2:
            printf("\nEnter element to insert  ");
            scanf("%d", &element);
            insertBack(element);
            break;
        case 3:
            printf("\nEnter the position after which node will be inserted ");
            scanf("%d", &pos);
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAt(pos, element);
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            deleteBack();
            break;
        case 6:
            printf("\nEnter position of element to delete ");
            scanf("%d", &pos);
            deleteAt(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            newHead = reverse();
            curr = newHead;
            while(curr!=NULL){
                printf("%d->",curr->data);
                curr = curr->next;
            }
            printf("X\n");
            break;
        }
    } while (ch < 9);

    return 0;
}