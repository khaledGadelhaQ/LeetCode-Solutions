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
  const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        
        int val = 0;
        if(root->val >= low && root->val <= high)
            val = root->val;

        return val + rangeSumBST(root->left, low , high) + rangeSumBST(root->right, low , high);

    }
};














