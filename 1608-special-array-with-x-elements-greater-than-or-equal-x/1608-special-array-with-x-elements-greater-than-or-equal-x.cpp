class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1);
        for(int i=0; i<n; i++){
            freq[min(n,nums[i])]++;
        }
        int sum = 0;
        for(int i=n;i>=1;i--){
            sum+=freq[i];
            if(sum==i) return i;
        }
        return -1;
    }
};