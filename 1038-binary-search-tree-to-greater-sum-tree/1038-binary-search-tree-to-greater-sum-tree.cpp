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
    void GreaterBST(TreeNode* root, int &num){
        if(!root) return;
        GreaterBST(root->right, num);

        root->val += num;
        num = root->val;

        GreaterBST(root->left, num);
    }
    TreeNode* bstToGst(TreeNode* root, int value = 0) {
        if(!root) return nullptr;
        int num {0};
        GreaterBST(root,num);
        return root;
        

    }
};