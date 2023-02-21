#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int cqueue[MAX];
int front = -1, rear = -1;

void enqueue(int item){
    if ((rear+1)%MAX == front){
        printf("Queue full\n");
    }
    else{
        if (front == -1){
            front = rear = 0;
        }
        else{
            rear = (rear+1)%MAX;
        }
        cqueue[rear] = item;
    }
}

void dequeue(){
    if (front == rear && front == -1){
        printf("Queue empty\n");
    }
    else{
        int item = cqueue[front];
        printf("Deleted item is: %d\n",item);
        if (front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
    }
}

void display(){
    if (front==-1 && rear==-1){
        printf("Queue empty\n");
    }
    else{
        if (front<=rear){
            for (int i = front; i<=rear; i++){
                printf("%d ", cqueue[i]);
            }
        }
        else{
            for (int i=front; i<MAX; i++){
                printf("%d ", cqueue[i]);
            }
            for (int i=0; i<=rear; i++){
                printf("%d ",cqueue[i]);
            }
        }
    }
}

int main()
{
    int ch, element;
    do
    {
        printf("\nMENU\n");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        }
    } while (ch < 4);

    return 0;
}