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

  bool isCompleteTree(TreeNode* root) {
      
    if(!root)

      return false;

    queue<TreeNode*> q;
    q.push(root);

    /// adding all the nodes to the queue 
    /// until the first node is nullptr
    /// then we break the loop 
    /// if there is a node after the nullptr we return false
    /// if all the rest nodes are all nullptrs we return true


    while(q.front() != nullptr){
      TreeNode* node = q.front() ; q.pop();

      q.push(node->left); q.push(node->right);

    }

    /// removing all the nullptr nodes if there is still
    /// nodes in the queue = false else true
    /// we can do that return q.empty();

    while(!q.empty() && q.front() == nullptr)
      q.pop();

    return q.empty();




  }
};