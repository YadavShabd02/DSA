#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node (Node* head, int val) {
        data = val;
        next = head;
    }
    Node (int val) {
        data = val;
        next = NULL;
    }
};

Node* InsertHead(Node* &head, int X) {
    Node* temp = new Node(head, X);
    return temp;
}

Node* Insert_Kth_pos(Node* &head, int X, int k) {
    if (head == NULL) {
        if(k == 1) return new Node(X);
        else return NULL;
    }

    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        cnt++;
        if (cnt == k - 1) {
            Node* ins = new Node(temp->next, X);
            temp->next = ins;
            break;
        }
        temp = temp->next;
    }
    return head;
}

void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;  

    cout << "Enter The Linkedlist:" << "\n";
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;  
        insertAtTail(head, x);
    }
    cout << "original LL: ";
    printLL(head);

    cout << "Enter the Value and Postion to be Inserted in the LL: ";
    int val;
    cin >> val;
    int pos;
    cin >> pos;

    Node* final_LL = Insert_Kth_pos(head, val, pos);
    cout << "Final LL: ";
    printLL(final_LL);

    return 0;
}