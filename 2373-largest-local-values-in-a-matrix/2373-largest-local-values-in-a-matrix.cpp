class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        int delrow[8] = {0,0,1,-1,1,-1,-1,1};
        int delcol[8] = {1,-1,0,0,1,1,-1,-1};
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                int mx = grid[i][j];
                for(int k=0;k<8;k++){
                    int nrow = i+delrow[k], ncol = j+delcol[k];
                    mx = max(mx,grid[nrow][ncol]);
                }
                ans[i-1][j-1] = mx;
            }
        }
        return ans;
    }
};