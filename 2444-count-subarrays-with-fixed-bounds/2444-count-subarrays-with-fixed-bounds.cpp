class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        int mini_index=-1;
        int maxi_index=-1;
        int defective_index=-1;
        long long  ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxk || nums[i]<mink)defective_index=i;

            if(nums[i]==maxk)maxi_index=i;

            if(nums[i]==mink)mini_index=i;

            int smaller=min(maxi_index,mini_index);

            int temp=smaller-defective_index;
            if(temp>0)ans+=temp;
        }
        return ans;
    }
};