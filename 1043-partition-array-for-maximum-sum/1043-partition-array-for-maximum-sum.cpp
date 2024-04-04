class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            int mx = -1, ans = 0;
            for(int j=i;j>=max(i-k+1,1);j--){
                mx = max(mx,arr[j-1]);
                int curr = (i-j+1)*mx + dp[j-1];
                ans = max(ans,curr);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};
