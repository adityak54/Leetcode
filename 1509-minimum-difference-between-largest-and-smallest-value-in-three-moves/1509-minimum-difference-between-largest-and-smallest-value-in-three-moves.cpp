class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(), nums.end());
        int lastThree = nums[n-4]-nums[0];
        int firstThree = nums[n-1]-nums[3];
        int firstnLastTwo = nums[n-3]-nums[1];
        int firstTwonLast = nums[n-2]-nums[2];
        return min(lastThree,min(firstThree,min(firstnLastTwo,firstTwonLast)));
    }
};