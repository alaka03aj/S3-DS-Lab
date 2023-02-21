#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char operatorStack[100];
int top = -1;

void operatorPush(char c) {
    if (top == 99) {
        printf("Stack overflow\n");
    } else {
        operatorStack[++top] = c;
    }
}

char operatorPop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return operatorStack[top--];
    }
}

char operatorPeek() {
    return operatorStack[top];
}

bool isEmpty() {
    return top == -1;
}

int getPrecedence(char c) {
    switch (c) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

bool hasHighPrec(char c1, char c2) {
    return getPrecedence(c1) >= getPrecedence(c2);
}

bool isOperand(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

bool isOpeningBracket(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClosingBracket(char c) {
    return c == ')' || c == ']' || c == '}';
}

void postfix(char str[]) {
    int n = strlen(str);
    char postFix[100];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (isOperand(str[i])) {
            postFix[k++] = str[i];
        } else if (!isOpeningBracket(str[i]) && !isClosingBracket(str[i])) {
            while (!isEmpty() && !isOpeningBracket(operatorPeek()) && hasHighPrec(operatorPeek(), str[i])) {
                postFix[k++] = operatorPop();
            }
            operatorPush(str[i]);
        } else if (isOpeningBracket(str[i])) {
            operatorPush(str[i]);
        } else if (isClosingBracket(str[i])) {
            while (!isEmpty() && !isOpeningBracket(operatorPeek())) {
                postFix[k++] = operatorPop();
            }
            if (!isEmpty() && isOpeningBracket(operatorPeek())) {
                operatorPop();
            } else {
                printf("Unmatched closing bracket: %c\n", str[i]);
                return;
            }
        }
    }
    while (!isEmpty()) {
        if (isOpeningBracket(operatorPeek())) {
            printf("Unmatched opening bracket: %c\n", operatorPop());
            return;
        } else {
            postFix[k++] = operatorPop();
        }
    }

    for (int j = 0; j < k; j++) {
        printf("%c", postFix[j]);
    }
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    postfix(infix);
    return 0;
}
