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
    int ge_right_most(TreeNode* root){
      while(root->right)
        root = root->right;
      return root->val;
    }
    int ge_left_most(TreeNode* root){
      while(root->left)
        root = root->left;
      return root->val;
    }
    int minDiffInBST(TreeNode* root) {
      if(!root)
       return INT_MAX;
      int l = INT_MAX , r = INT_MAX , m = INT_MAX;
      if(root->left) l = ge_right_most(root->left);
      if(root->right) r = ge_left_most(root->right);
      m = min(abs(root->val - l) , abs(r - root->val));
      return min(m,min(minDiffInBST(root->left),minDiffInBST(root->right)));
      
    }   
};