class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0; i<times.size(); i++){
            int u = times[i][0], v = times[i][1], w = times[i][2];
            adj[u].push_back({v,w});
        }
        
        int ans = 0;
        vector<int> time(n+1, INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        time[k] = 0;
        
        while(!pq.empty()){
            int currTime = pq.top().first, node = pq.top().second;
            pq.pop();
            
            for(auto &it: adj[node]){
                int timeReq = it.second, nextNode = it.first;
                if(time[nextNode]>timeReq+currTime){
                    time[nextNode] = timeReq+currTime;
                    pq.push({time[nextNode], nextNode});
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            ans = max(ans,time[i]);
        }
        return (ans==INT_MAX) ? -1 : ans;
        
    }
};