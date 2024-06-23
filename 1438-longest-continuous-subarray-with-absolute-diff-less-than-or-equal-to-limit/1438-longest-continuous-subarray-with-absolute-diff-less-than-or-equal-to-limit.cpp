class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1;
        deque<int> mn={nums[0]}, mx={nums[0]};
        int j=0;
        for(int i=1; i<nums.size(); i++){
            while(!mx.empty() && mx.front()<nums[i]) mx.pop_front();
            mx.push_front(nums[i]);
            
            while(!mn.empty() && mn.front()>nums[i]) mn.pop_front();
            mn.push_front(nums[i]);
            
            if(mx.back()-mn.back()>limit){
                while(j<i && mx.back()-mn.back()>limit){
                    if(nums[j]==mn.back()) mn.pop_back();
                    if(nums[j]==mx.back()) mx.pop_back();
                    j++;
                }
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
    
};