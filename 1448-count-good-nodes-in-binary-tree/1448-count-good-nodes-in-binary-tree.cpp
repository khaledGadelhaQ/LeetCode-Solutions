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

  int fun(TreeNode* root , int max_){
    if(!root)
      return 0;
    int mid = root->val >= max_; 
    int l = fun(root->left , max(root->val,max_));
    int r = fun(root->right , max(root->val,max_));
    return l + r + mid ;
  }
  int goodNodes(TreeNode* root) {
   
   if(!root)
     return 0;
    return fun(root,root->val);
  }
};