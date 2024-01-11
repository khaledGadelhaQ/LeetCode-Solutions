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
    int solve(TreeNode* root, int min_ , int max_){
        if(!root) return 0;
        int value = max( abs(root->val - min_) , abs(root->val - max_));
        int new_min = min(root->val, min_);
        int new_max = max(root->val, max_);
        return max({value,solve(root->right ,new_min , new_max ) , solve(root->left, new_min , new_max )});
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};