class Solution {
public:
    int f(int i, int prev, vector<vector<int>> &grid,vector<vector<int>> &dp){
        int n = grid.size(), m = grid[0].size();
        if(i==n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int ans = INT_MAX;
        for(int j=0;j<m;j++){
            if(j==prev) continue;
            int curr = grid[i][j]+f(i+1,j,grid,dp);
            ans = min(ans,curr);
        }
        return dp[i][prev]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
       return f(0,m,grid,dp); 
    }
};