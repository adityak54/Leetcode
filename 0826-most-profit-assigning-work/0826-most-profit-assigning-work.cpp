#define pi pair<int,int>
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        int n = worker.size();
        sort(worker.begin(), worker.end());
        vector<pi> diffprof;
        for(int i=0; i<n; i++){
            diffprof.push_back({difficulty[i],profit[i]});
        }
        sort(diffprof.begin(), diffprof.end());
        int j=0;
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            while(j<n && diffprof[j].first<=worker[i]){
                pq.push(diffprof[j].second);
                j++;
            }
            if(!pq.empty()) ans += pq.top();
        }
        return ans;
    }
};