class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        while(start<=end){
            int mid = start-(start-end)/2;
            int ahead = mid==n-1?INT_MIN:nums[mid+1];
            int behind = mid==0?INT_MIN:nums[mid-1];
            if(nums[mid]>=behind && nums[mid]>=ahead) return mid;
            else if(nums[mid]>=behind && nums[mid]<ahead) start = mid+1;
            else end = mid-1;
        }
        return 1;
    }
};