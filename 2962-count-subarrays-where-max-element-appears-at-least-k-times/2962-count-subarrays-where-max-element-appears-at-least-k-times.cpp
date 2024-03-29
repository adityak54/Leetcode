class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int ans = 0;
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        int cntmx = 0;
        int i=0, j=0;
        while(j<n){
            if(nums[j]==mx) cntmx++;
            if(cntmx==k){
                while(i<=j && cntmx==k){
                    if(nums[i]==mx) cntmx--;
                    ans+=n-j;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};