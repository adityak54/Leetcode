class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0, flips=0;
        queue<int> flipEnds;
        for(int i=0; i<=nums.size(); i++){
            if(!flipEnds.empty() && flipEnds.front()==i){
                flipEnds.pop();
                flips--;
            }
            if(i==nums.size()) break;
            if(nums[i] && flips&1){
                flipEnds.push(i+k);
                flips++;
                ans++;
            }else if(!nums[i] && !(flips&1)){
                flipEnds.push(i+k);
                flips++;
                ans++;
                nums[i]=1;
            }
        }
        return flips?-1:ans;
    }
};