#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

int stack[MAX];
int end = -1;

void push(int s[], int val) {
    if (end == MAX - 1) {
        printf("The Stack has reached its limit\n");
        return;  
    }
    s[++end] = val;
}

int pop(int s[]) {
    if (end == -1) {
        printf("No element in Stack to Pop\n"); 
        return -1;
    }
    return s[end--];
}

int top(int s[]) {
    if (end == -1) {
        printf("The Stack is empty\n");
        return -1;
    }
    return s[end];
} 

int size(int s[]) {
    return end + 1;
}

void display(int s[]) {
    if (end == -1) {
        printf("Stack is empty\n");
        return;  
    }
    printf("Stack elements: ");
    for (int i = end; i >= 0; i--) {
        printf("%d ", s[i]);
    }
    printf("\n");
}

int main() {
    int n, value;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(stack, value);
    }
    
    display(stack);

    return 0;
}
