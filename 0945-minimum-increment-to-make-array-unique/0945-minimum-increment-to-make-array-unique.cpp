class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> freq(1e5+1);
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        
        for(int i=0; i<=1e5; i++){
            if(freq[i]>1){
                if(i==1e5){
                    ans+=((freq[i]-1)*freq[i])/2;
                }else{
                    ans+=freq[i]-1;
                    freq[i+1]+=freq[i]-1;
                } 
            }
        }
        return ans;
    }
};