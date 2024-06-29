class Solution {
    void dfs(int node, int currParent, vector<vector<int>> &adj, vector<vector<int>> &ans){
        for(auto child : adj[node]){
            if(ans[child].empty() || ans[child].back()!=currParent){
                ans[child].push_back(currParent);
                dfs(child,currParent,adj,ans);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), adj(n);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
        }
        
        for(int i=0; i<n; i++){
            dfs(i,i,adj,ans);
        }
        
        return ans;
    }
};