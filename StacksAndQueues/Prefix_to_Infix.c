#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char* stack[MAX];
int top = -1;

void push(char* str) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = str;
}

char* pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

char* prefixToInfix(char* prefix) {
    char* result;
    int len = strlen(prefix);
    
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];
        
        if (isalnum(c)) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = c;
            operand[1] = '\0';
            push(operand);
        }
        else if (isOperator(c)) {
            char* op1 = pop();
            char* op2 = pop();
            int size = strlen(op1) + strlen(op2) + 4;
            result = (char*)malloc(size * sizeof(char));
            snprintf(result, size, "(%s%c%s)", op1, c, op2);
            free(op1);
            free(op2);
            push(result);
        }
    }
    
    result = pop();
    return result;
}

int main() {
    char prefix[MAX];
    
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    
    char* infix = prefixToInfix(prefix);
    printf("The Infix Expression: %s\n", infix);
    
    free(infix);
    return 0;
}
