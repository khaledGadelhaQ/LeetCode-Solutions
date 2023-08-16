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
  bool is_same(TreeNode* root, TreeNode* subRoot){

    if(!root && !subRoot)
      return true;
    if(!root || !subRoot || root->val != subRoot->val )
      return false;
    
    return is_same(root->left,subRoot->left) && is_same(root->right,subRoot->right) ;
  }

  bool C = false;
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {

    if(!root) 
      return false;
    if(!subRoot && root)
      return true;

    bool A = isSubtree(root->left,subRoot);
    bool B = isSubtree(root->right,subRoot);

    if(root->val == subRoot->val)
      C = is_same(root,subRoot);

    return A || B || C ;
  }
};