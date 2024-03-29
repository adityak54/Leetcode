class Solution {
private:
    int dp[600][101][101];
public:
    int f(int i,int len,int n,int m,vector<string> &strs){
        if(i==len) return 0;
        if(n==0 && m==0) return 0;
        if(dp[i][n][m]!=-1) return dp[i][n][m];
        int take = 0, notTake = 0;
        int cnt0 = 0, cnt1 = 0;
        for(int j=0;j<strs[i].size();j++){
            strs[i][j]=='0'?cnt0++:cnt1++;
        }
        if(cnt0<=m && cnt1<=n) take = 1+f(i+1,len,n-cnt1,m-cnt0,strs);
        notTake = f(i+1,len,n,m,strs);
        return dp[i][n][m]=max(take,notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        memset(dp,-1,sizeof(dp));
        return f(0,len,n,m,strs);
    }
};