#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int stack[MAX];
int minStack[MAX];
int top = -1;
int minTop = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = x;
    if (minTop == -1 || x <= minStack[minTop]) {
        minStack[++minTop] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int x = stack[top--];
    if (x == minStack[minTop]) {
        minTop--;
    }
    return x;
}

int topElement() {
    if (top == -1) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}

int getMin() {
    if (minTop == -1) {
        printf("Stack is empty\n");
        exit(1);
    }
    return minStack[minTop];
}

int main() {
    push(3);
    push(5);
    printf("Minimum: %d\n", getMin());
    
    push(2);
    push(1);
    printf("Minimum: %d\n", getMin());
    
    pop();
    printf("Minimum: %d\n", getMin());
    
    pop();
    printf("Top Element: %d\n", topElement());
    printf("Minimum: %d\n", getMin());
    
    return 0;
}
