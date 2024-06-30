class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        for(int i=0; i<=n; i++){
            parent.push_back(i);
        }
        rank.resize(n+1);
    }
    int findUpar(int u){
        if(parent[u]==u) return u;
        return parent[u] = findUpar(parent[u]);
    }
    void unionByRank(int u, int v){
        int ultp_u = findUpar(u), ultp_v = findUpar(v);
        if(ultp_u==ultp_v) return;
        if(rank[ultp_u]>rank[ultp_v]){
            parent[ultp_v] = ultp_u;
        }else if(rank[ultp_u]<rank[ultp_v]){
            parent[ultp_u] = ultp_v;
        }else{
            rank[ultp_v]++;
            parent[ultp_u] = ultp_v;
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        DSU a = DSU(n);
        DSU b = DSU(n);
        for(int i=0; i<edges.size(); i++){
            int type = edges[i][0], u = edges[i][1], v = edges[i][2];
            if(type==3){
                if(a.findUpar(u)==a.findUpar(v)){
                    ans++;
                }else{
                    a.unionByRank(u,v);
                    b.unionByRank(u,v);
                }
            }
        }
        
        for(int i=0; i<edges.size(); i++){
            int type = edges[i][0], u = edges[i][1], v = edges[i][2];
            if(type==1){
                if(a.findUpar(u)==a.findUpar(v)){
                    ans++;
                }else{
                    a.unionByRank(u,v);
                }
            }else if(type==2){
                if(b.findUpar(u)==b.findUpar(v)){
                    ans++;
                }else{
                    b.unionByRank(u,v);
                }
            }
        }
        int cnta = 0, cntb = 0;
        for(int i=1; i<=n; i++){
            if(a.parent[i]==i) cnta++;
            if(b.parent[i]==i) cntb++;
        }
        return (cnta>1 || cntb>1) ? -1 : ans;
    }
};