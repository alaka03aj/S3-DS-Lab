// Implement a Queue using arrays

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int data){
    if (rear == MAX -1){
        printf("Queue is full\n");
    }
    else {
        if (front == -1 && rear == -1){
            front = 0;
            queue[front] = data;
            rear = 0;
        }
        else{
            rear++;
            queue[rear] = data;
        }
    }
}

void dequeue(){
    if (front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        int item = queue[front];
        printf("Deleted item: %d\n",item);
        if (front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front++;
        }
    }
}

void display(){
    if (front == rear && front == -1){
        printf("Queue is empty!\n");
    }
    else{
        for (int i = front; i<=rear; i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}                 

void main(){
    int ch, item;
    do{
        printf("\nMENU\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("\nEnter item: ");
                scanf("%d",&item);
                enqueue(item);
                break;
            
            case 2:
                dequeue();
                break;
            
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Wrong choice!\n");
                break;
        }
    } while (ch<=4);
}