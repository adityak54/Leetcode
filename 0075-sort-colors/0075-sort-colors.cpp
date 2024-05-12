class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1, it = 0;
        while(it<=right){
            if(nums[it]==0){
                swap(nums[it],nums[left]);
                left++;
                it++;
            }else if(nums[it]==2){
                swap(nums[it],nums[right]);
                right--;
            }
            else it++;
        }
        
    }
};