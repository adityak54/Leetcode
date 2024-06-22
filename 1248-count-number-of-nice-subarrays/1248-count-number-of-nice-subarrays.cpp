class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int cntOdd = 0;
        vector<int> dp(nums.size()+1);
        dp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&1){
                cntOdd++;
            }
            if(cntOdd>=k){
                ans += dp[cntOdd-k];
            }
            dp[cntOdd]++;
        }
        return ans;
    }
};