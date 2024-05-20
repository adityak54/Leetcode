class Solution {
    int ans = 0;
public:
    void f(int i,int currXor,vector<int> &nums){
        int n = nums.size();
        if(i==n){
            if(currXor!=-1) ans+=currXor;
            return;
        }
        f(i+1,currXor,nums); // notTake
        if(currXor==-1) currXor = nums[i];
        else currXor^=nums[i];
        f(i+1,currXor,nums); // take
    }
    int subsetXORSum(vector<int>& nums) {
        f(0,-1,nums);
        return ans;
    }
};