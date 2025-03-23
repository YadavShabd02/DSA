#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderRecursive(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorderRecursive(root->left, res);
    res.push_back(root->val);
    inorderRecursive(root->right, res);
}

int main() {
    // Constructing a binary search tree:
    //      2
    //     / \
    //    1   3
    TreeNode* root = new TreeNode(2);
    root->left  = new TreeNode(1);
    root->right = new TreeNode(3);

    vector<int> result;
    inorderRecursive(root, result);

    cout << "Inorder Recursive: ";
    for (int val : result) cout << val << " ";
    return 0;
}
