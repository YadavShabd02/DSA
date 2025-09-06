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

Node* delete_kth_pos(Node* &head, int k) {
    if(head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        if(k == 1) {
            delete(head);
        }
        else return NULL;
    }
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete(temp);
        return head;
    }

    Node* temp = head;
    int cnt = 0;
    Node* prev = NULL;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) {
            prev->next = temp->next;
            temp->next = NULL;
        }
        prev = temp;
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

    cout << "Enter the Postion to be Deleted in the LL: ";
    int pos;
    cin >> pos;

    Node* final_LL = delete_kth_pos(head, pos);
    cout << "Final LL: ";
    printLL(final_LL);

    return 0;
}