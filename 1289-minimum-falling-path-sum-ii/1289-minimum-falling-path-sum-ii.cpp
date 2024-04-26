class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> curr(n,INT_MAX), prev(n,INT_MAX);
        for(int j=0;j<n;j++) prev[j]=grid[0][j];
        for(int i=1;i<n;i++){
            for(int k=0; k<n; k++){
                for(int j=0;j<n;j++){
                    if(j==k) continue;
                    curr[k] = min(curr[k],grid[i][k]+prev[j]);
                } 
            }
            prev = curr;
            for(int j=0;j<n;j++) curr[j]=INT_MAX;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++) ans=min(ans,prev[i]);
        return ans;
    }
};