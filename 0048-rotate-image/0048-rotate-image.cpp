class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // mirror
        for(int r=0; r<n; r++){
            for(int c=r+1; c<n; c++){
                if(r==c) continue;
                swap(matrix[r][c],matrix[c][r]);
            }
            reverse(matrix[r].begin(), matrix[r].end());
        }
        
        //reverse
    //     for(int r=0; r<n; r++){
    //         reverse(mat[r].begin(), mat[r].end());
    //     }
    }
};