class Solution {
public:
    static bool cmp(int a, int b){
        string sa = to_string(a);
        string sb = to_string(b);
        return sa+sb>sb+sa;
    }
    string largestNumber(vector<int>& nums) {
        string ans = "";
        int n = nums.size();
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<n;i++){
            ans += to_string(nums[i]);
        }
        while(*ans.begin()=='0' && ans.size()!=1) ans.erase(0,1);
        return ans;
    }
};