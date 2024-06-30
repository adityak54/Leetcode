class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto &it: m){
            if(m.find(it.first+1)!=m.end()){
                ans = max(ans,it.second+m[it.first+1]);
            }
        }
        return ans;
    }
};