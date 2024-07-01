class Solution {
public:
    int findDiameter(int node, int parent, vector<int> adj[], int &d){
        int mx = 0, mx2 = 0;
        for(auto child: adj[node]){
            if(child==parent) continue;
            int h = 1+findDiameter(child,node,adj,d);
            if(h>mx){
                mx2 = mx;
                mx = h;
            }
            else if(h>mx2) mx2 = h;
        }
        d = max(d, mx+mx2);
        return mx;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1, m = edges2.size()+1;
        vector<int> adj1[n], adj2[m];
        
        for(int i=0; i<n-1; i++){
            int u = edges1[i][0], v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        
        for(int i=0; i<m-1; i++){
            int u = edges2[i][0], v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int d1 = 0, d2 = 0;
        findDiameter(0,-1,adj1,d1);
        findDiameter(0,-1,adj2,d2);
        int d3 = (d1+1)/2 + (d2+1)/2 + 1;
        return max(d1,max(d2,d3));
    }
};