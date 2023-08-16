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


  int res  ;
  
  int kthSmallest(TreeNode* root, int k ) {
    
    fun(root,k);
    return res;
  
  }
  void fun(TreeNode* root , int  &k){
   
    if(!root) return;

    fun(root->left,k);
    
    //if(!root->right) return;

    if(--k == 0){
      res = root->val ; 
      return ;
    }

    fun(root->right,k);
    
  }
};