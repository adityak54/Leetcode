class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1);
        for(int i=n-1;i>=0;i--){
            int ans = 0, mx = -1;
            for(int j=i;j<min(n,i+k);j++){
                mx = max(arr[j],mx);
                int curr = mx*(j-i+1)+dp[j+1];
                ans = max(ans,curr);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};