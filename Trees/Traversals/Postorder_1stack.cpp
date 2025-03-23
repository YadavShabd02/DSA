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

vector<int> postOrderOneStack(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    
    stack<TreeNode*> st;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;
    
    while (current || !st.empty()) {
        // Go left as far as possible
        if (current) {
            st.push(current);
            current = current->left;
        } else {
            TreeNode* peekNode = st.top();
            // If right child exists and not visited yet, go right
            if (peekNode->right && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                // Pop and visit
                res.push_back(peekNode->val);
                st.pop();
                lastVisited = peekNode;
            }
        }
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

    vector<int> result = postOrderOneStack(root);

    cout << "Post-order using 1 stack: ";
    for (int val : result) cout << val << " ";
    cout << endl;
    return 0;
}
