#include <iostream>
#include <algorithm>  // for std::max, std::abs

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If dfsHeight returns -1, it means the tree is imbalanced
        return dfsHeight(root) != -1;
    }

private:
    int dfsHeight(TreeNode* root) {
        // An empty tree has a height of 0
        if (root == nullptr) return 0;

        // Recursively compute the height of the left subtree
        int leftHeight = dfsHeight(root->left);
        // If left subtree is imbalanced, propagate the -1 upwards
        if (leftHeight == -1) return -1;

        // Recursively compute the height of the right subtree
        int rightHeight = dfsHeight(root->right);
        // If right subtree is imbalanced, propagate the -1 upwards
        if (rightHeight == -1) return -1;

        // If the current node is imbalanced, return -1
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Otherwise, return the actual height
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    /*
        Example tree:
             1
            / \
           2   3
          / \
         4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    bool result = sol.isBalanced(root);

    cout << (result ? "Balanced" : "Not Balanced") << endl;

    // Clean up (in a real application you'd want to delete the entire tree)
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
