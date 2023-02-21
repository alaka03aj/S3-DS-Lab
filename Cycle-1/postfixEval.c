#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int d){
    stack[++top] = d;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

bool isDigit(char c){
    return (c>='0' && c<='9');
}

int performOperation(char op, int x, int y){
    switch(op){
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;
        case '^':
            return pow(x,y);
        default:
            return -1;
    }
}

int eval(char str[]){
    int n = strlen(str);
    for (int i=0; i<n; i++){
        if (str[i] == ' '){
            continue;
        }
        if (isDigit(str[i])){
            int num = 0;
            while (isDigit(str[i])){
                num = num*10 + (int) (str[i] - '0');
                i++;
            }
            push(num);
        }
        else{
            int y = pop();
            int x = pop();
            int res = performOperation(str[i],x,y);
            push(res);
        }
    }
    return peek();
}

int main(){
    char postfix[100];
    printf("Enter postfix expression separated by space: ");
    gets(postfix);
    int r = eval(postfix);
    printf("%d",r);
    return 0;
}