class Solution {
public:
    void dfs(int node, int parent,int n,vector<int> &currPath,vector<vector<int>> &ans,vector<vector<int>> &graph){
        if(node==n-1){
            ans.push_back(currPath);
            return;
        }
        for(auto nextNode : graph[node]){
            if(nextNode==parent) continue;
            currPath.push_back(nextNode);
            dfs(nextNode,node,n,currPath,ans,graph);
            currPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> currPath;
        currPath.push_back(0);
        dfs(0,-1,n,currPath,ans,graph);
        return ans;
    }
};