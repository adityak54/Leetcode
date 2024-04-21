class Solution {
public:
    bool dfs(int node, int destination, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;
        if(node==destination) return true;
        for(auto &it: adj[node]){
            if(!vis[it]){
                if(dfs(it,destination,vis,adj)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n);
        return dfs(source,destination,vis,adj);
    }
};