class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid = nums.size()-1;
        while(mid>=left){
            if(nums[mid]==0){
                swap(nums[left],nums[mid]);
                left++;
            }
            else if(nums[mid]==2){
                swap(nums[right],nums[mid]);
                right--,mid--;
            }
            else mid--;
        }
    }
};