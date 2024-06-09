class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> m;
        m[0] = 1;
        int currSum = 0, ans = 0;
        for(int i=0; i<n; i++){
            currSum += nums[i];
            int rem = currSum%k;
            if(rem<0) rem+=k;
            if(m.find(rem)!=m.end()) ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
};