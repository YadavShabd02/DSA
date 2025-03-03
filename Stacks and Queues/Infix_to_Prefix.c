#include <stdio.h>
#include <ctype.h>  // For isalnum()
#include <string.h>

#define MAX 100  

char stack[MAX];
int top = -1;

// Function to push to stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop from stack
char pop() {
    if (top == -1) return -1;  // Stack empty case
    return stack[top--];
}

// Function to get precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void reverse (char* str) {
    int n = strlen(str);
    for (int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int j = 0; // Index for postfix array
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop and add to postfix until '(' is found
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Remove '(' from stack
        }
        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';  // Null terminate string
}

void infixToPrefix(char* infix, char* prefix) {
    char tempPostfix[MAX];
    reverse(infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    infixToPostfix(infix, tempPostfix);
    
    reverse(tempPostfix);
    strcpy(prefix, tempPostfix);
}

// Main function
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("The Prefix Expression: %s", prefix);

    return 0;
}
