class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int n = happiness.size();
        int cnt = 0;
        sort(happiness.begin(),happiness.end());
        for(int i=n-1;i>n-1-k;i--){
            ans+=max(happiness[i]-cnt,0);
            cnt++;
        }
        return ans;
    }
};