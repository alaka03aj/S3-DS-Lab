// Implement a Stack using arrays
    
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int data){
    if (top == MAX-1){
        printf("Overflow\n");
    }
    else{
        stack[++top] = data;
    }
}

void pop(){
    if (top == -1){
        printf("Underflow\n");
    }
    else{
        int item = stack[top];
        top--;
        printf("Deleted item is: %d\n", item);
    }
}

void peek(){
    if (top!=-1){
        printf("Value at the top is: %d\n", stack[top]);
    }
    else{
        printf("Stack empty!\n");
    }
}

void isEmpty(){
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
}

void isFull(){
    if (top == MAX - 1){
        printf("Stack is full\n");
    }
    else{
        printf("Stack is not full\n");
    }
}

void display(){
    for (int i=top; i>=0; i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

void main(){
    int ch, data;
    do{
        printf("\nMENU\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Check if stack is full\n5. Check if stack is empty\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter element to be pushed: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                isFull();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("\nWrong choice!\n");
                break;
        }
    } while (ch<=6);
}


