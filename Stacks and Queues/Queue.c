#include <stdio.h>

#define MAX 100 

int Queue[MAX];
int front = -1, rear = -1;  


int isEmpty() {
    return front == -1 || front > rear;
}

void push(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot push %d\n", value);
        return;
    }
    if (front == -1) front = 0;
    Queue[++rear] = value;
}

int pop() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot pop\n");
        return -1;
    }
    int Popped_val = Queue[front++];
    return Popped_val;
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", Queue[i]);
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
        push(value);  
    }
    
    display();
    return 0;
}
