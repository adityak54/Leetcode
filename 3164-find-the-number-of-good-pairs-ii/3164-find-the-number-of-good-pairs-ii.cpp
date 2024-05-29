class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        long long ans = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++) mp[nums2[i]*k]++;
        for(int i=0;i<n;i++){
            for(int j=1;j<=sqrt(nums1[i]);j++){
                if(nums1[i]%j==0){
                    if(nums1[i]/j==j) ans+=mp[j];
                    else{
                        ans+=mp[j];
                        ans+=mp[nums1[i]/j];
                    }
                }
            }
        }
        return ans;
    }
};