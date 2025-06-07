#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to find the Lowest Common Ancestor
struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
    if (root == NULL)
        return NULL;

    if (root == p || root == q)
        return root;

    struct Node* left = lowestCommonAncestor(root->left, p, q);
    struct Node* right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
        return root;
    
    return (left != NULL) ? left : right;
}

// Example usage
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
             \
              6
    */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->right = createNode(6);
    

    struct Node* p = root->left->left;    // node 4
    struct Node* q = root->left->right->right;   // node 6

    struct Node* lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
        printf("LCA = %d\n", lca->data);  // prints 2
    else
        printf("One or both nodes not in tree\n");

    return 0;
}
