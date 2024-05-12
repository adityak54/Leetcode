class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int j=2;j<=numRows;j++){
            vector<int> currRow(j);
            for(int i=0;i<j;i++){
                if(i>0) currRow[i]+=ans.back()[i-1];
                if(i<j-1) currRow[i]+=ans.back()[i];              
            }
            ans.push_back(currRow);
        }
        return ans;
    }
};