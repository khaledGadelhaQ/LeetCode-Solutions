/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stk;

    void add_nodes(TreeNode* root){
        while(root){
            stk.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
     add_nodes(root);
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        add_nodes(node->right);
        return node->val;
    }
    
    bool hasNext() {
      return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */