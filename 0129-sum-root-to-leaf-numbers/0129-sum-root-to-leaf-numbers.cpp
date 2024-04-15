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
    int f(TreeNode* root, int currVal){
        if(!root->left && !root->right){
            return currVal*10+root->val;
        }
        currVal = currVal*10+root->val;
        int left = 0, right = 0;
        if(root->left) left = f(root->left,currVal);
        if(root->right) right = f(root->right,currVal);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return f(root,0);
    }
};