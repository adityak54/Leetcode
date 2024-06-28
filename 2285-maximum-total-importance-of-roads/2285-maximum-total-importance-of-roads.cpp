class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> roadFreq(n);
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0], v = roads[i][1];
            roadFreq[u]++, roadFreq[v]++;
        }
        int currVal = n;
        sort(roadFreq.begin(), roadFreq.end(), greater<int>());
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += 1LL*roadFreq[i]*currVal;
            currVal--;
        }
        return ans;
    }
};