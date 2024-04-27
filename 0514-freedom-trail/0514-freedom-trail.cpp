class Solution {
public:
    int f(int i, int j, string &ring, string &key,vector<vector<int>> &dp){
        int n = ring.size(), m = key.size();
        if(i==m) return 0;
        if(dp[j][i]!=-1) return dp[j][i];
        int ans = INT_MAX;
        int k = j, cnt = 0;
        while(1){
            if(ring[k]==key[i]){
                ans = min(ans,1+cnt+f(i+1,k,ring,key,dp));
                break;
            }
            cnt++;
            k==0?k=n-1:k--;
        }
        k = j, cnt = 0;
        while(1){
            if(ring[k]==key[i]){
                ans = min(ans,1+cnt+f(i+1,k,ring,key,dp));
                break;
            }
            cnt++;
            k==n-1?k=0:k++;
        }
        return dp[j][i]=ans;
        
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,ring,key,dp);
    }
};