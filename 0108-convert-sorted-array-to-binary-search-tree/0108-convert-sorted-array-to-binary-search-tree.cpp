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
   TreeNode* insert(vector<int> vec, int st , int ed){
    
    if(st > ed)
      return nullptr;
    int min = (st+ed)/2 ;
    TreeNode* root = new TreeNode(vec[min]);
    root->left = insert(vec,st,min-1);
    root->right = insert(vec,min+1,ed);

    return root;

   }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return insert(nums,0,nums.size()-1);
    }
  };
