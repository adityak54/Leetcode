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
    TreeNode* insertNode(TreeNode* root, TreeNode* child) { 
        if(root==NULL){
            return child;
        }
        if(!child) return root;
        if(root->val>child->val){
            root->left = insertNode(root->left,child);
        }
        else root->right = insertNode(root->right,child);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            return insertNode(root->right,root->left);
        }
        else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        root->left = deleteNode(root->left,key);
        return root;
    }
};