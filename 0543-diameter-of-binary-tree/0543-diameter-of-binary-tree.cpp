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
  int res = 0;
    int findDiameter(TreeNode* root){
      
      if(!root)
        return 0 ;
      int left , rigth ;
      left = findDiameter(root->left);
      rigth = findDiameter(root->right);
     
      res = max(res,left+rigth);

      return 1 + max(left,rigth);
      


    }
    int diameterOfBinaryTree(TreeNode* root) {
      
      findDiameter(root);
      
      return res;
        
    }
};