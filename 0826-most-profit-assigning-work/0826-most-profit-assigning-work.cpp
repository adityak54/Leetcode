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
        int j=0,currMax = 0;
        for(int i=0; i<n; i++){
            while(j<n && diffprof[j].first<=worker[i]){
                currMax = max(currMax, diffprof[j].second);
                j++;
            }
            ans += currMax;
        }
        return ans;
    }
};