class Solution {
public:
    void f(int i, vector<int> &curr,set<vector<int>> &s,vector<int> &nums){
        int n = nums.size();
        if(i==n) {
            s.insert(curr);
            return;
        }
        curr.push_back(nums[i]);
        f(i+1,curr,s,nums);
        curr.pop_back();
        f(i+1,curr,s,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> curr;
        f(0,curr,s,nums);
        for(auto &it: s){
            ans.push_back(it);
        }
        return ans;
    }
};