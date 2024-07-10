class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                ans = min(ans,mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return (ans==INT_MAX) ? nums.size() : ans;
    }
};