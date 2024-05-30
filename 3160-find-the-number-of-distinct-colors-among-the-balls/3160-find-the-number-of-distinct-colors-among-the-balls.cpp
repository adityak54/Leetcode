class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        unordered_map<int,int> mp1, mp2;
        for(int i=0; i<n; i++){
            int x = queries[i][0], y = queries[i][1];
            if(mp1.find(x)!=mp1.end()){
                if(mp2[mp1[x]]==1) mp2.erase(mp1[x]);
                else mp2[mp1[x]]--;
            }
            mp1[x] = y;
            mp2[y]++;
            ans.push_back(mp2.size());
        }
        return ans;
    }
};