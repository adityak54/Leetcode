class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26,0);
        for(int i=n-1;i>=0;i--){
            int curr = s[i]-'a';
            int left = max(curr-k,0);
            int right = min(curr+k,25);
            for(int j=left;j<=right;j++){
                dp[curr] = max(dp[curr],dp[j]);
            }
            dp[curr]+=1;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};