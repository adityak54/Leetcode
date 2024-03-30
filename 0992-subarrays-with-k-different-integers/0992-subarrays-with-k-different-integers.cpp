class Solution {
public:
    int f(int n, vector<int> &nums, int k){
        unordered_map<int,int> m;
        int i=0,j=0,ans=0;
        while(j<n){
            m[nums[j]]++;
            while(i<=j && m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0) m.erase(nums[i]);
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return f(n,nums,k)-f(n,nums,k-1);
    }
};