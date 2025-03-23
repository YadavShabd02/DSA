#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postorderRecursive(TreeNode* root, vector<int>& res) {
    if (!root) return;
    postorderRecursive(root->left, res);
    postorderRecursive(root->right, res);
    res.push_back(root->val);
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
    postorderRecursive(root, result);

    cout << "Postorder Recursive: ";
    for (int val : result) cout << val << " ";
    return 0;
}
