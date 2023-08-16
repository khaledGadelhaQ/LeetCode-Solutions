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
    void fun(TreeNode* root, int val ){
      if(val > root->val){
           if(!root->right){
              TreeNode* node = new TreeNode(val);
              root->right = node;
            }
            fun(root->right,val);

      }else if(val < root->val){
           if(!root->left){
              TreeNode* node = new TreeNode(val);
              root->left = node;
            }
            fun(root->left,val);

      }

      
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
         TreeNode* node = new TreeNode(val);
         return node;
        }
        fun(root,val);
        return root ;
    }
};