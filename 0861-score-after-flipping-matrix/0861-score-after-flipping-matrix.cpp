class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    if(grid[i][j]) grid[i][j] = 0;
                    else grid[i][j] = 1;
                }
            }
        }
        int ans = 0;
        for(int j=m-1;j>=0;j--){
            int cnt1 = 0;
            for(int i=0;i<n;i++) if(grid[i][j]) cnt1++;
            if(2*cnt1<n) ans+=(n-cnt1)*(1<<(m-j-1));
            else ans+=cnt1*(1<<(m-j-1));
        }
        return ans;
    }
};