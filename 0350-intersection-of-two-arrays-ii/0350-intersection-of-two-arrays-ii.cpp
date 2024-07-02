class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq1(1001), freq2(1001);
        
        for(int i=0; i<nums1.size(); i++){
            freq1[nums1[i]]++;
        }
        
        for(int i=0; i<nums2.size(); i++){
            freq2[nums2[i]]++;
        }
        
        vector<int> ans;
        for(int i=0; i<1001; i++){
            int mn = min(freq1[i], freq2[i]);
            while(mn--) ans.push_back(i);
        }
        return ans;
    }
};