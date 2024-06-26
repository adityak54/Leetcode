class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, i=0, j=0;
        map<int,int> m;
        while(j<n){
            m[nums[j]]++;
            while(m[nums[j]]>k && i<=j) m[nums[i++]]--;
            ans = max(ans,j-i+1);
            j++;
        }   
        return ans;
    }
};