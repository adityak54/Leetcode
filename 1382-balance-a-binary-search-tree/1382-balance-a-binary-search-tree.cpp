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
    void inorderTraversal(TreeNode* node, vector<int> &inOrder){
        if(!node) return;
        inorderTraversal(node->left,inOrder);
        inOrder.push_back(node->val);
        inorderTraversal(node->right,inOrder);
    }
    TreeNode* balanceBST(int start, int end, vector<int> &inOrder){
        if(start>end) return NULL;
        int mid = start-(start-end)/2;
        TreeNode* curr =  new TreeNode(inOrder[mid]);
        curr->left = balanceBST(start,mid-1,inOrder);
        curr->right = balanceBST(mid+1,end,inOrder);
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;
        TreeNode* node = root;
        inorderTraversal(node,inOrder);
        return balanceBST(0,inOrder.size()-1,inOrder);
    }
};