class Solution {
public:
    int f(int i,int n, vector<int> &arr,int k,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 0,mx = -1;
        for(int j=i;j<min(i+k,n);j++){
            mx = max(mx,arr[j]);
            int curr = mx*(j-i+1)+f(j+1,n,arr,k,dp);
            ans = max(ans,curr);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,n,arr,k,dp);
    }
};