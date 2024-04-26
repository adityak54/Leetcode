class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> curr(n,INT_MAX), prev(n,INT_MAX);
        for(int j=0;j<n;j++) prev[j]=grid[0][j];
        for(int i=1;i<n;i++){
            for(int k=0; k<n; k++){
                int ans = INT_MAX;
                for(int j=0;j<n;j++){
                    if(j==k) continue;
                    ans = min(ans,grid[i][k]+prev[j]);
                } 
                curr[k] = ans;
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++) ans=min(ans,prev[i]);
        return ans;
    }
};