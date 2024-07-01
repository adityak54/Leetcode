class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(k));
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                int currSum = (nums[i]+nums[j])%k;
                dp[i][currSum] = max(dp[i][currSum],1+dp[j][currSum]);
                ans = max(ans,dp[i][currSum]+1);
            }
        }
        return ans;
    }
};