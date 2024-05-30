class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size(), q = queries.size();
        vector<int> ans, occ;
        for(int i=0; i<n; i++){
            if(nums[i]==x) occ.push_back(i);
        }
        for(int i=0; i<q; i++){
            if(queries[i]>occ.size()) ans.push_back(-1);
            else ans.push_back(occ[queries[i]-1]);
        }
        return ans;
    }
};