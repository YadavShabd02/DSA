#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

// Utility function to print DLL
void printList(Node* head) {
    Node* temp = head;
    cout << "DLL: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at beginning
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at position (1-based index)
void insertAtPosition(Node*& head, int pos, int val) {
    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;

    if (!temp || !temp->next) {
        insertAtTail(head, val);
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete head node
void deleteHead(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}

// Delete tail node
void deleteTail(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next) temp = temp->next;

    temp->prev->next = nullptr;
    delete temp;
}

// Delete node by value (first occurrence)
void deleteByValue(Node*& head, int val) {
    Node* temp = head;
    while (temp && temp->data != val) temp = temp->next;

    if (!temp) return; // Not found

    if (temp == head) {
        deleteHead(head);
    } else if (!temp->next) {
        deleteTail(head);
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    insertAtHead(head, 20);
    insertAtHead(head, 10);
    printList(head); // 10 20

    insertAtTail(head, 30);
    insertAtTail(head, 40);
    printList(head); // 10 20 30 40

    insertAtPosition(head, 3, 25); // Insert at position 3
    printList(head); // 10 20 25 30 40

    deleteHead(head);
    printList(head); // 20 25 30 40

    deleteTail(head);
    printList(head); // 20 25 30

    deleteByValue(head, 25);
    printList(head); // 20 30

    return 0;
}
