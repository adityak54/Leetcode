class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        int i = 0;
        long long int curr = 1;
        while(curr<=n){
            if(i<nums.size() && nums[i]<=curr){
                curr += nums[i++];
            }else{
                curr += curr;
                ans++;
            }
        }
        return ans;
    }
};