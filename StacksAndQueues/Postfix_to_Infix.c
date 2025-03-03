// Time Complexity --> O(n)-while loop   +  O(n1 + n2)-adding two different strings of length n1 and n2 which rounds to O(n)
// Space Complexity --> O(n)-storing n elements in stack

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char* stack[MAX];
int top = -1;


void push(char* str) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = str;
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


char* postfixToInfix(char* postfix) {
    char* result; 
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        

        if (isalnum(c)) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = c;
            operand[1] = '\0';
            push(operand);
        }
  
        else if (isOperator(c)) {
            char* op2 = pop();
            char* op1 = pop();
            
            // Calculate the size needed for the new string:
            // length(op1) + length(op2) + 3 extra for operator and parentheses + 1 for the null terminator.
            int size = strlen(op1) + strlen(op2) + 4;
            result = (char*)malloc(size * sizeof(char));
            
            // Format the new string as: (op1 operator op2)
            snprintf(result, size, "(%s%c%s)", op1, c, op2);
            
            free(op1);
            free(op2);
            
            // Push the newly formed string back onto the stack
            push(result);
        }
    }
    
    // After processing the entire postfix expression, the stack holds the complete infix expression
    result = pop();
    return result;
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    char* infix = postfixToInfix(postfix);
    printf("The Infix Expression: %s\n", infix);


    free(infix);

    return 0;
}
