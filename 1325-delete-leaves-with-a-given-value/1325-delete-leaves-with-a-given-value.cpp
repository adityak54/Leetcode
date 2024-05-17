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
    bool f(TreeNode* root, int target){
        if(root==NULL) return 0;
        
        if(f(root->left,target)) root->left = NULL;
        if(f(root->right,target)) root->right = NULL;
        
        if(!root->left && !root->right && root->val==target){
            return 1;
        }
        return 0;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(f(root,target)) return NULL;
        return root;
    }
};