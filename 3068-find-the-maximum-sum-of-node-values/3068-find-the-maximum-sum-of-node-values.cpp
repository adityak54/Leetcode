class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;
        int n = nums.size();
        int cnt = 0, mnChange=INT_MAX;
        for(int i=0;i<n;i++){
            int valAfterXor = nums[i]^k;
            if(valAfterXor>nums[i]) cnt++;
            mnChange = min(mnChange, abs(valAfterXor-nums[i]));
            ans+=max(valAfterXor,nums[i]);
        }
        if(cnt&1 && cnt) ans-=mnChange;
        return ans;
    }
};