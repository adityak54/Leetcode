class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int temp = 0;
        for(auto i : nums)
            temp ^= i;

        temp = (temp^k);
        
        int cnt = 0;
        while(temp){
            cnt++;
            temp = (temp&(temp-1));
        }

        return cnt;
    }
};