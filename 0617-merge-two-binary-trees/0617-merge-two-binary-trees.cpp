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
    TreeNode* f(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return NULL;
        TreeNode* ans = new TreeNode(0);
        if(node1) ans->val += node1->val;
        if(node2) ans->val += node2->val;
        
        if(node1 && node2){
            ans->left = f(node1->left,node2->left);
            ans->right = f(node1->right,node2->right);
        }else if(node1){
            ans->left = f(node1->left,node2);
            ans->right = f(node1->right,node2);
        }else if(node2){
            ans->left = f(node1,node2->left);
            ans->right = f(node1,node2->right);
        }
        return ans;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* node1 = root1, *node2 = root2;
        return f(node1,node2);
    }
};