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

struct NodeState {
    TreeNode* node;
    int state;
    NodeState(TreeNode* n, int s) : node(n), state(s) {}
};

void allInOneTraversal(TreeNode* root, 
                       vector<int>& pre, 
                       vector<int>& in, 
                       vector<int>& post) {
    if (!root) return;
    
    stack<NodeState> st;
    st.push(NodeState(root, 1)); // state = 1 => Preorder phase
    
    while (!st.empty()) {
        NodeState &top = st.top();
        
        // state = 1 -> Preorder
        if (top.state == 1) {
            pre.push_back(top.node->val);
            top.state++;
            
            if (top.node->left) {
                st.push(NodeState(top.node->left, 1));
            }
        }
        // state = 2 -> Inorder
        else if (top.state == 2) {
            in.push_back(top.node->val);
            top.state++;
            
            if (top.node->right) {
                st.push(NodeState(top.node->right, 1));
            }
        }
        // state = 3 -> Postorder
        else {
            post.push_back(top.node->val);
            st.pop();
        }
    }
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

    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    allInOneTraversal(root, preorder, inorder, postorder);

    cout << "Preorder:   ";
    for (int val : preorder) cout << val << " ";
    cout << "\nInorder:    ";
    for (int val : inorder) cout << val << " ";
    cout << "\nPostorder:  ";
    for (int val : postorder) cout << val << " ";
    cout << endl;

    return 0;
}
