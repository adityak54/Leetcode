class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // 5 2 4 0 1
        unordered_map<int,int> m;
        int currSum = 0;
        for(int i=0; i<n; i++){
            currSum += nums[i];
            if(currSum%k==0 && i>0) return true;
            int rem = currSum%k;
            if(m.find(rem)!=m.end() && i-m[rem]>1) return true;
            m.insert({currSum%k,i});
        }
        return false;
            
    }
};