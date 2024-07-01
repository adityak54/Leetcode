class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int left = INT_MAX, right = -1, top = INT_MAX, bottom = -1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    left = min(left,j);
                    right = max(right,j);
                    top = min(top,i);
                    bottom = max(bottom,i);
                }
            }
        }
        
        return (right-left+1)*(bottom-top+1);
    }
};