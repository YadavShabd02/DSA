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

vector<int> postOrderTwoStacks(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    
    stack<TreeNode*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);
        
        if (node->left)  st1.push(node->left);
        if (node->right) st1.push(node->right);
    }
    
    while (!st2.empty()) {
        res.push_back(st2.top()->val);
        st2.pop();
    }
    
    return res;
}

int main() {
    /*
            1
           / \
          2   3
         / \  / \
        4  5 6   7
    */
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left   = new TreeNode(4);
    root->left->right  = new TreeNode(5);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = postOrderTwoStacks(root);

    cout << "Post-order using 2 stacks: ";
    for (int val : result) cout << val << " ";
    cout << endl;
    return 0;
}
