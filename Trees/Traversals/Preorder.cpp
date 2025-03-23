#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderRecursive(TreeNode* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);
    preorderRecursive(root->left, res);
    preorderRecursive(root->right, res);
}

int main() {
    // Constructing a simple binary tree:
    //      1
    //     / \
    //    2   3
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> result;
    preorderRecursive(root, result);

    cout << "Preorder Recursive: ";
    for (int val : result) cout << val << " ";
    return 0;
}
