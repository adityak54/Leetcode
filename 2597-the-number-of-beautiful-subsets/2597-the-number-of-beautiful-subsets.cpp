class Solution {
public:
    int f(int i,int n,int k,vector<int> &check, vector<int> &nums){
        if(i==n) return 1;
        int take = 0, notTake = 0;
        notTake = f(i+1,n,k,check,nums);
        if(nums[i]-k<0 || !check[nums[i]-k]){
            check[nums[i]]++;
            take = f(i+1,n,k,check,nums);
            check[nums[i]]--;
        }
        return take+notTake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> check(1001);
        return f(0,n,k,check,nums)-1;
    }
};