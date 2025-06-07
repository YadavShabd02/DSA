#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Returns true if there is a root‑to‑leaf path whose
// node‐sum equals `targetSum`.
bool hasPathSum(Node* root, int targetSum) {
    if (!root) 
        return false;
    // If we're at a leaf, check if the remaining sum matches
    if (!root->left && !root->right) 
        return (targetSum == root->data);
    // Otherwise, subtract current node and recurse down
    int rem = targetSum - root->data;
    return hasPathSum(root->left,  rem) 
        || hasPathSum(root->right, rem);
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    Node* root = new Node(1);
    root->left  = new Node(2);
    root->right = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    cout << boolalpha;
    cout << "Path sum 7? "  << hasPathSum(root, 7)  << "\n"; // 1→2→4 = 7  ⇒ true
    cout << "Path sum 8? "  << hasPathSum(root, 8)  << "\n"; // 1→2→5 = 8  ⇒ true
    cout << "Path sum 10? " << hasPathSum(root, 10) << "\n"; // no such ⇒ false

    return 0;
}
