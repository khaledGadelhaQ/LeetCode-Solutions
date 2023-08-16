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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q)
      return true;
    if(!p || !q || p->val != q->val )
      return false;
    
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) ;
  }

  void fun(TreeNode* p ){

    if(!p)
     return;

    if(p->left && p->right && p->left->val < p->right->val)

      swap(p->left,p->right);

    if(p->left && !p->right)
      // if the null is on the right we swap them 
      // to make it on the left
      swap(p->left,p->right);

    fun(p->left);
    fun(p->right);

  }

  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
    if(!root1 && !root2)
      return true;
    
    if(!root1 || !root2 || root1->val !=  root2->val)
      return false;
    
    /// this function rearrange the tree nodes
    /// so that the nodes with small values be on the left of
    /// their parent.
    /// consider a null node is less than any node 
    /// so null node will always be  the left of the parent
  
    fun(root1);
    fun(root2);
     
    // isSameTree is a function that compare two trees 
    // if they are same it returns true , otherwise false.
    return isSameTree(root1,root2);
    
  }
};