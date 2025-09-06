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

class Solution {
public:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* t1 = l1; 
        Node* t2 = l2;
        Node* dn = new Node(-1);
        Node* curr = dn;
        int carry = 0;
        
        while (t1 != NULL || t2 != NULL) {
            int sum = carry; 
            if (t1) {
                sum += t1->data;
                t1 = t1->next;
            }
            if (t2) {
                sum += t2->data;
                t2 = t2->next;
            }
            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }
        
        if (carry) {
            curr->next = new Node(carry);
        }

        Node* result = dn->next;
        delete dn;
        return result;
    }

    void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
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
    

};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int m;
    cout << "Enter m: ";
    cin >> m;

    Solution sol;

    cout << "Enter The Linkedlist 1:" << "\n";
    Node* head1 = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;  
        sol.insertAtTail(head1, x);
    }

    cout << "Enter The Linkedlist 2:" << "\n";
    Node* head2 = NULL;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;  
        sol.insertAtTail(head2, x);
    }

    cout << "original LL1: ";
    sol.printLL(head1);

    cout << "original LL2: ";
    sol.printLL(head2);

    Node* final_LL = sol.addTwoNumbers(head1, head2);
    cout << "Final LL: ";
    sol.printLL(final_LL);

    return 0;
}