#define pi pair<int,int>
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> ans(n,INT_MAX);
        vector<pi> adj[n];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1], time = edges[i][2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue<pi,vector<pi>,greater<pi>> q;
        ans[0] = 0;
        q.push({0,0});
        while(!q.empty()){
            int node = q.top().second, currtime = q.top().first;
            q.pop();
            if(currtime>ans[node]) continue;
            for(auto it:adj[node]){
                int nextNode = it.first, time = it.second;
                if(currtime+time<ans[nextNode] && disappear[nextNode]>currtime+time){
                    ans[nextNode] = currtime+time;
                    q.push({ans[nextNode],nextNode});
                }
            }
        }
        for(int i=0;i<n;i++) if(ans[i]==INT_MAX) ans[i] = -1;
        return ans;
    }
};