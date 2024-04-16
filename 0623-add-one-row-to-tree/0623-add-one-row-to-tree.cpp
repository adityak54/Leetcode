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
    void dfs(TreeNode* node,int val,int level,int depth){
        if(level==depth-1){
            TreeNode* node1 = new TreeNode(val);
            TreeNode* node2 = new TreeNode(val);
            node1->left = node->left;
            node2->right = node->right;
            node->left = node1, node->right = node2;
            return;
        }
        if(node->left) dfs(node->left,val,level+1,depth);
        if(node->right) dfs(node->right,val,level+1,depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        dfs(root,val,1,depth);
        return root;
    }
};