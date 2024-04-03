class Solution {
private:
    bool isPalin(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    int f(int i,int n,string &s,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalin(i,j,s)){
                int curr = 1+f(j+1,n,s,dp);
                ans = min(ans,curr);
            }
        }
        return dp[i]=ans;
    }
    
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};