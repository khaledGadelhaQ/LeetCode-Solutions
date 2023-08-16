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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> vec;
    if(!root)
      return vec;
    vector<int> res;
    res.push_back(root->val);
   
    deque<TreeNode*> dq;
    dq.push_back(root);

    while(!dq.empty()){

      vec.push_back(res); res.clear();
      
      int sz = dq.size();
        while(sz--){

        TreeNode* node = dq.front();
        dq.pop_front();
        
        if(node->left){

          dq.push_back(node->left); 
          res.push_back(node->left->val);

        }if(node->right){

          dq.push_back(node->right);
          res.push_back(node->right->val);
        }
      } 
      
    }
    return vec;
  }
};