class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int currXor = 0;
        for(int i=0; i<n; i++) currXor ^= nums[i];
        int val = 1;
        while(1){
            if((val&currXor)==val) break;
            val = val<<1;
        }
        int ans1 = 0, ans2 = 0;
        for(int i=0;i<n;i++){
            if((val&nums[i])==val) ans1 ^= nums[i];
            else ans2 ^= nums[i];
        }
        return {ans1,ans2};
    }
};