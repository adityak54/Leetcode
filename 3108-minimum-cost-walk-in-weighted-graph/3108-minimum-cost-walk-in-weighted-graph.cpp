class Solution {
public:
    class DSU{
    
    public:
        vector<int> rank,parent,weight;
    DSU(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        weight.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
        for(int i=0;i<=n;i++) weight[i] = INT_MAX;
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v,int w){
        int ultp_u = findUPar(u);
        int ultp_v = findUPar(v);
        // if(ultp_u == ultp_v) return;
        if(rank[ultp_u]<=rank[ultp_v]){
            weight[ultp_v]&=weight[ultp_u];
            weight[ultp_v]&=w;
            parent[ultp_u] = ultp_v;
            
        }
        else{
            weight[ultp_u]&=weight[ultp_v];
            weight[ultp_u]&=w;
            parent[ultp_v] = ultp_u;
        }
    }
};
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        int m = edges.size();
        DSU ds = (n);
        for(int i=0;i<m;i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            ds.unionByRank(u,v,w);
        }
        int q = query.size();
        for(int i=0;i<q;i++){
            int start = query[i][0], end = query[i][1], w = query[i][2];
            if(start==end){
                ans.push_back(0);
                continue;
            }
            if(ds.findUPar(start)!=ds.findUPar(end)) ans.push_back(-1);
            else{
                ans.push_back(ds.weight[ds.findUPar(start)]);
            }
        }
        return ans;
        
    }
};