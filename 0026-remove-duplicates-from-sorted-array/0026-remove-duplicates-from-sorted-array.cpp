class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=0,n=nums.size(),ans=1;
        while(i<n){
            if(nums[i]!=nums[j]){
                nums[j+1] = nums[i];
                ans++;
                j++;
            }
            i++;
        }
        return ans;
    }
};