class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int> currHeight(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') currHeight[j]++;
                else currHeight[j] = 0; 
            }
            stack<int> s;
            int currMax = 0;
            for(int k=0;k<=m;k++){
                while(!s.empty() && (k==m || currHeight[s.top()]>=currHeight[k])){
                    int height = currHeight[s.top()];
                    s.pop();
                    int width = 0;
                    if(s.empty()) width = k;
                    else width=k-s.top()-1;
                    currMax = max(currMax,height*width);
                }
                s.push(k);
            }
            ans = max(ans,currMax);
            
        }
        return ans;
    }
};