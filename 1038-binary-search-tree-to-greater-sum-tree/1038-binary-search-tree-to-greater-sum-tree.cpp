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
    void f(TreeNode* root, int &curr){
        if(!root) return;
        if(root->right){
            f(root->right,curr);
        }
        curr += root->val;
        root-> val = curr;
        if(root->left){
            f(root->left,curr);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int curr = 0;
        TreeNode* node = root;
        f(node, curr);
        return root;
    }
};