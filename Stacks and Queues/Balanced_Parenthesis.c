#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

char stack[MAX]; 
int end = -1;

void push(char s[], char val) {
    if (end == MAX - 1) {
        printf("The Stack has reached its limit\n");
        return;  
    }
    s[++end] = val;
}

char pop(char s[]) {
    if (end == -1) {
        return '\0';  
    }
    return s[end--];
}

int size() {
    return end + 1;
}

int bal_parenthesis(char s[], char str[], int n) {
    for (int i = 0; i < n; i++) { 
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(s, str[i]);
        } 
        else {  
            if (size() == 0) return 0;

            char el = pop(s);

            if ((str[i] == ')' && el != '(') ||
                (str[i] == ']' && el != '[') ||
                (str[i] == '}' && el != '{')) {
                return 0; 
            }
        }
    }
    return size() == 0;  // If stack is empty, it's balanced
}

int main() {
    char str[MAX]; 
    printf("Enter the Parenthesis String: ");
    scanf("%s", str);  

    int n = 0;
    while (str[n] != '\0') n++;

    if (bal_parenthesis(stack, str, n)) 
        printf("The given parenthesis is balanced\n");
    else 
        printf("The given parenthesis is not balanced\n");

    return 0;
}
