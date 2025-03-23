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

vector<int> inorderIterative(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}

int main() {
    // Constructing a binary search tree:
    //      2
    //     / \
    //    1   3
    TreeNode* root = new TreeNode(2);
    root->left  = new TreeNode(1);
    root->right = new TreeNode(3);

    vector<int> result = inorderIterative(root);

    cout << "Inorder Iterative: ";
    for (int val : result) cout << val << " ";
    return 0;
}
