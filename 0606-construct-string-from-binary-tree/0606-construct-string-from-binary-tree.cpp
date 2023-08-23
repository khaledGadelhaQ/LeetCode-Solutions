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
    
    string tree2str(TreeNode* node) {
        if(!node)
         return "";
        string str = "";

        str += to_string(node->val) ;

        if(node->right && !node->left)
          str+="()";
        if(node->left)
          str += '(' + tree2str(node->left) + ')';
        if(node->right)
          str += '(' + tree2str(node->right) + ')';
        
        return str;


    }
};