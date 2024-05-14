class Solution {
public:
    int delrow[4] = {0,0,-1,1};
    int delcol[4] = {1,-1,0,0};
    int f(int r, int c, vector<vector<int>> &vis,vector<vector<int>> &grid){
        int n = grid.size(), m= grid[0].size();
        vis[r][c] = 1;
        int nextMax = 0,ans = grid[r][c];
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i], ncol=c+delcol[i];
            if(nrow<0 || ncol<0 || nrow==n || ncol==m || vis[nrow][ncol] 
               || grid[nrow][ncol]==0) continue;
            nextMax = max(nextMax,f(nrow,ncol,vis,grid));
        }
        vis[r][c] = 0;
        return ans+nextMax;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    ans = max(ans,f(i,j,vis,grid));
                }
            }
        }
        return ans;
    }
};