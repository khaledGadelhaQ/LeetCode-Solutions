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
    int res = 0 ;
    unordered_map<int, int> mp;
    bool isPalindrome() {
        int odd = 0;
        for (auto entry : mp) {
            if (entry.second % 2 == 1) {
                odd++;
            }
        }
        return odd <= 1;
    }


    void BT(TreeNode* root){
        if(!root) return;
        mp[root->val]++;

        BT(root->left);
        BT(root->right);

        if(!root->left && !root->right && isPalindrome() )
            res++;
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        BT(root);
        return res;
    }
};