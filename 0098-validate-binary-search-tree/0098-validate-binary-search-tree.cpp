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
    bool f(TreeNode* root, long long int minVal, long long int maxVal){
        if(root==NULL) return true;
        if(root->val<=minVal || root->val>=maxVal) return false;
        return f(root->left,minVal,root->val) && f(root->right,root->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return f(root,LONG_MIN,LONG_MAX);
    }
};