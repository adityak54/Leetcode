class Solution {
    void f(int node, int currCnt, int &ans, vector<int> &vis, map<int,int> &pos,vector<int> &edges){
        vis[node] = 1;
        pos[node] = currCnt;
        int nextNode = edges[node];
        if(nextNode==-1) return;
        if(!vis[nextNode]) f(nextNode,currCnt+1,ans,vis,pos,edges);
        else if(pos.find(nextNode)!=pos.end()) ans = max(ans, currCnt-pos[nextNode]+1);
    }
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1, n = edges.size();
        vector<int> vis(n);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                map<int,int> pos;
                f(i,1,ans,vis,pos,edges);
            }
        }
        return ans;
    }
};