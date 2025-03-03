#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char* stack[MAX];
int top = -1;

void push(char* s) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = s;
}

char* pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

char* postfixToPrefix(char* exp) {
    int n = strlen(exp);
    char *res;
    for (int i = 0; i < n; i++) {
        char c = exp[i];
        if (isalnum(c)) {
            char* temp = (char*)malloc(2 * sizeof(char));
            temp[0] = c;
            temp[1] = '\0';
            push(temp);
        }
        else if (isOperator(c)) {
            char* op2 = pop();
            char* op1 = pop();
            int size = strlen(op1) + strlen(op2) + 2;
            res = (char*)malloc((size + 1) * sizeof(char));
            snprintf(res, size + 1, "%c%s%s", c, op1, op2);
            free(op1);
            free(op2);
            push(res);
        }
    }
    res = pop();
    return res;
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    char* prefix = postfixToPrefix(exp);
    printf("Prefix expression: %s\n", prefix);
    free(prefix);
    return 0;
}
