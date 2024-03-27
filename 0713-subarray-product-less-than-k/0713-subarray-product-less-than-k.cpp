class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0,product = 1;
        int i=0,j=0;
        while(j<n){
            product*=nums[j];
            while(product>=k && i<=j) product/=nums[i],i++;
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};