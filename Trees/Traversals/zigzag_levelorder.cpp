#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            int index = leftToRight ? i : (n - 1 - i);
            level[index] = node->val;
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        res.push_back(level);
    }
    return res;
}

int main() {
    // Constructing a simple binary tree:
    //           1
    //         /   \
    //        2     3
    //       / \   / \
    //      4   5 6   7
    TreeNode* root = new TreeNode(1);
    root->left         = new TreeNode(2);
    root->right        = new TreeNode(3);
    root->left->left   = new TreeNode(4);
    root->left->right  = new TreeNode(5);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> levels = zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";
    for (auto level : levels) {
        for (int val : level)
            cout << val << " ";
        cout << "\n";
    }
    return 0;
}
