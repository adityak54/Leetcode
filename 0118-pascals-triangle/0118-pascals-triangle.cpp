class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        numRows--;
        while(numRows--){
            int n = ans.back().size();
            vector<int> currRow(n+1);
            for(int i=0;i<n+1;i++){
                if(i>0) currRow[i]+=ans.back()[i-1];
                if(i<n) currRow[i]+=ans.back()[i];              
            }
            ans.push_back(currRow);
        }
        return ans;
    }
};