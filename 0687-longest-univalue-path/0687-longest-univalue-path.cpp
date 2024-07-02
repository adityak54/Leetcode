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
    int f(TreeNode* root, int &ans){
        if(!root->left && !root->right) return 1;
        bool chkl = false, chkr = false;
        int left = 0, right = 0;
        int currAns = 0;
        if(root->left){  
            left = f(root->left,ans);
            if(root->left->val==root->val) chkl = true;
        }
        if(root->right){
            right = f(root->right,ans);
            if(root->right->val==root->val) chkr = true;
        }
        if(chkl && chkr){
            ans = max(left+right,ans);
            currAns = max(left,right);
        }
        else if(chkl) currAns = left;
        else if(chkr) currAns = right;
        ans = max(ans,currAns);
        return 1+currAns;
        
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        if(!root) return 0;
        f(root,ans);
        return ans;
    }
};