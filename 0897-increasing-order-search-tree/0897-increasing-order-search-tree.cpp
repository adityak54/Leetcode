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
    void f(TreeNode* node, vector<int> &inorder){
        if(node==NULL) return;
        f(node->left,inorder);
        inorder.push_back(node->val);
        f(node->right,inorder);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
        TreeNode* node = root;
        f(node,inorder);
        // for(int i=0; i<inorder.size(); i++) cout<<inorder[i]<<" ";
        TreeNode* temp = new TreeNode(inorder[0]);
        TreeNode* ans = temp;
        for(int i=1; i<inorder.size(); i++){
            temp->right = new TreeNode(inorder[i]);
            temp = temp->right;
        }
        return ans;
    }
};