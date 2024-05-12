class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, prevMax = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int currMax = max(nums[i],nums[i]+prevMax);
            ans = max(ans,currMax);
            prevMax = currMax;
        }
        return ans;
    }
};