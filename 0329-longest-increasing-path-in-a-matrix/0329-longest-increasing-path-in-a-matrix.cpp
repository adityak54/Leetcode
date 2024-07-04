class Solution {
    int f(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(dp[r][c]!=-1) return dp[r][c];
        int ans = 1;
        int drow[4] = {0,0,-1,1};
        int dcol[4] = {-1,1,0,0};
        for(int i=0; i<4; i++){
            int nr = r+drow[i], nc = c+dcol[i];
            if(nr<0 || nc<0 || nr==matrix.size() || nc==matrix[0].size()) continue;
            if(matrix[nr][nc]>matrix[r][c]) ans = max(ans,1+f(nr,nc,matrix,dp));
        }
        return dp[r][c]=ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),-1));
        int ans = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(dp[i][j]==-1){
                    ans = max(ans,f(i,j,matrix,dp));
                }
            }
        }
        return ans;
    }
};