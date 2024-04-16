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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int currDepth = q.front().second;
            q.pop();
            if(currDepth==depth) break;
            if(currDepth==depth-1){
                TreeNode* node1 = new TreeNode(val);
                TreeNode* node2 = new TreeNode(val);
                node1->left = node->left, node2->right = node->right;
                node->left = node1, node->right = node2;
            }
            if(node->left) q.push({node->left,currDepth+1});
            if(node->right) q.push({node->right,currDepth+1});
        }
        return root;
    }
};