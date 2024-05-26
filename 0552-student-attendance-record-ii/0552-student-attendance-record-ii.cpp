class Solution {
    int mod = 1e9+7;
    int f(int i,int currA, int currL, int n, vector<vector<vector<int>>> &dp){
        if(i==n) return 1;
        if(dp[i][currA][currL]!=-1) return dp[i][currA][currL];
        int absent = 0, late = 0, present = 0;
        if(!currA) absent = f(i+1,1,0,n,dp)%mod;
        if(currL<2) late = f(i+1,currA,currL+1,n,dp)%mod;
        present = f(i+1,currA,0,n,dp)%mod;
        return dp[i][currA][currL]=(absent+(present+late)%mod)%mod;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,0,0,n,dp);
    }
};