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
    string ans = "";
    bool isSmall(string &a, string &b){
        int n = min(a.size(),b.size());
        for(int i=0;i<n;i++){
            if(a[i]<b[i]) return false;
            if(a[i]>b[i]) return true;
        }
        if(a.size()<=b.size()) return false;
        return true;
    }
    void f(TreeNode* root,string &currString){
        currString.push_back(char('a'+root->val));
        if(!root->left && !root->right){
            reverse(currString.begin(),currString.end());
            if(ans.empty() || isSmall(ans,currString)){
                ans = currString;
            }
            reverse(currString.begin(),currString.end());
            currString.pop_back();
            return;
        }
        if(root->left){
            f(root->left,currString);
        }
        if(root->right){
            f(root->right,currString);
        }
        currString.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string currString = "";
        f(root,currString);
        return ans;
    }
};