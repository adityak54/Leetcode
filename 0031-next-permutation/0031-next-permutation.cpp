class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // 1 5 4 3 2
        bool chk = false;
        int mnInd = -1, mn = nums.back();
        for(int j=n-1;j>=0;j--){
            for(int i=n-1;i>j;i--){
                if(nums[i]>nums[j]){
                    chk = true;
                    swap(nums[i],nums[j]);
                    sort(nums.begin()+j+1,nums.end());
                    return;
                }
            }
        }
        if(!chk) sort(nums.begin(),nums.end());
    }
};