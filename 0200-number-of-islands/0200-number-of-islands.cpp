class Solution {
    private:
    int delrow[4] = {0,0,1,-1};
    int delcol[4] = {1,-1,0,0};
public:
    void f(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[row][col] = 1;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i], ncol = col+delcol[i];
            if(nrow<0 || nrow==n || ncol<0 || ncol==m) continue;
            if(!vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                f(nrow,ncol,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    f(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};