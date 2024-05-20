class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums.back();
        int i=0, j=1;
        while(1){
            if(nums[i]!=nums[j]){
                nums[i] = 1e9+5;
                nums[j] = 1e9+5;
                while(i<n && (nums[i]==1e9+5 || i==j)) i++;
                while(j<n && (nums[j]==1e9+5 || i==j)) j++;
            }else{
                j++;
            }
            
            if(i==n) return nums[j];
            if(j==n) return nums[i];
        }
        return 1;
    }
};