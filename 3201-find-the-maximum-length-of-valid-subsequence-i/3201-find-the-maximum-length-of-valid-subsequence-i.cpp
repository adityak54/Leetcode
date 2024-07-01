class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        // even
        int cnte = 0, cnto = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&1) cnto++;
            else cnte++;
        }
        ans = max(cnto, cnte);
        
        
        //odd
        int cnt = 1, prev=nums[0];
        for(int i=1; i<nums.size(); i++){
            if((nums[i]+prev)&1){
                cnt++;
                prev = nums[i];
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};