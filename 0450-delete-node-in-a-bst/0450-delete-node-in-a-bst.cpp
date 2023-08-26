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
class Solution {
public:
    TreeNode* min_node(TreeNode* node){
        while(node && node->left)
          node = node->left;
        return node;
    }
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
        return nullptr;
    }

    if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        } else if (!root->right) {
            TreeNode* tmp = root->left;
            delete root;
            return tmp;
        }

        TreeNode* mn = min_node(root->right);
        root->val = mn->val;
        root->right = deleteNode(root->right, mn->val);
    }

    return root;
}

};