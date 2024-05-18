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
    int ans = 0;
    int f(TreeNode* node){
        if(node==NULL) return 0;
        int curr = node->val-1;
        int left = f(node->left);
        int right = f(node->right);
        ans+=abs(left)+abs(right);
        curr+=left+right;
        return curr;
    }
public:
    int distributeCoins(TreeNode* root) {
        f(root);
        return ans;
    }
};