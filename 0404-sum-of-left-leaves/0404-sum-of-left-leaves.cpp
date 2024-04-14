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
    bool chk = false;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left && !root->right){
            if(chk) return root->val;
            return 0;
        }
        int left = 0, right = 0;
        if(root->left) chk = true,left = sumOfLeftLeaves(root->left);
        if(root->right) chk = false,right = sumOfLeftLeaves(root->right);
        return left+right;
        
    }
};