#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int stack[MAX];
int top = -1;
int currentMin; // Keeps track of the current minimum

// Check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Check if the stack is full
int isFull() {
    return (top == MAX - 1);
}

// Push operation using the formula (2*x - currentMin) for new minimum
void push(int x) {
    if (isFull()) {
        printf("Stack Overflow\n");
        exit(1);
    }

    // If the stack is empty, just push x and set currentMin to x
    if (isEmpty()) {
        stack[++top] = x;
        currentMin = x;
    }
    // If x is greater or equal to currentMin, push x normally
    else if (x >= currentMin) {
        stack[++top] = x;
    }
    // If x is less than currentMin, encode it and update currentMin
    else {
        int encoded = 2 * x - currentMin; // encode
        stack[++top] = encoded;
        currentMin = x; // update the currentMin to the new value
    }
}

// Pop operation (decoding if necessary)
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }

    int topVal = stack[top--];

    // If the popped value is less than the currentMin, it's encoded
    if (topVal < currentMin) {
        int originalVal = currentMin;       // the real value we pushed
        currentMin = 2 * currentMin - topVal; // restore the old min
        return originalVal;
    } else {
        // Otherwise, it's a normal value
        return topVal;
    }
}

// Return the top element without removing it
int topElement() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        exit(1);
    }

    // If top value is encoded, the real top is currentMin
    if (stack[top] < currentMin) {
        return currentMin;
    } else {
        return stack[top];
    }
}

// Return the current minimum
int getMin() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        exit(1);
    }
    return currentMin;
}

int main() {
    push(3);
    push(5);
    printf("Current Min: %d\n", getMin()); // Should be 3

    push(2);
    push(1);
    printf("Current Min: %d\n", getMin()); // Should be 1

    printf("Popped: %d\n", pop()); // Pops 1
    printf("Current Min: %d\n", getMin()); // Should be 2

    printf("Popped: %d\n", pop()); // Pops 2
    printf("Top Element: %d\n", topElement()); // Should be 5
    printf("Current Min: %d\n", getMin()); // Should be 3

    return 0;
}
