#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderIterative(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);
        // Right child is pushed first so that left is processed first.
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return res;
}

int main() {
    // Constructing a simple binary tree:
    //      1
    //     / \
    //    2   3
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> result = preorderIterative(root);

    cout << "Preorder Iterative: ";
    for (int val : result) cout << val << " ";
    return 0;
}
