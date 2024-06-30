class Solution {
public:
    bool check(int l, vector<vector<char>> &matrix){
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<=m-l; i++){
            for(int j=0; j<=n-l; j++){
                int sum = 0;
                for(int r=0; r<l; r++){
                    for(int c=0; c<l; c++){
                        sum+=int(matrix[i+r][j+c]-'0');
                    }
                }
                if(sum==l*l) return true;
            }
        }
        return false;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        int start = 1, end = min(m,n);
        while(start<=end){
            int mid = start + (end-start)/2;
            if(check(mid,matrix)){
                ans = mid*mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};