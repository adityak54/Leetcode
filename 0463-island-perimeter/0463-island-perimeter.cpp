class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        int delrow[] = {0,0,1,-1};
        int delcol[] = {1,-1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    for(int k=0;k<4;k++){
                        int nrow = i+delrow[k], ncol = j+delcol[k];
                        if(nrow<0 || ncol<0 || nrow==n || ncol==m || !grid[nrow][ncol]){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};