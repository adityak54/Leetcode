class Solution {
    bool f(int player, int currTotal,int mask,int maxChoosableInteger,int desiredTotal,vector<vector<int>> &dp){
        if(currTotal>=desiredTotal){
            return true;
        }
        if(dp[player][mask]!=-1) return dp[player][mask];
        bool ans = false;
        for(int i=1; i<=maxChoosableInteger; i++){
            if((mask&(1<<i))) continue;
            ans |= f(0,currTotal+i,(mask^(1<<i)),maxChoosableInteger,desiredTotal,dp);
        }
        if(player) return dp[player][mask] = ans; 
        return dp[player][mask] = !ans;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal==0) return true;
        if((maxChoosableInteger*(maxChoosableInteger+1))/2<desiredTotal) return false;
        vector<vector<int>> dp(2,vector<int>(1<<21,-1));
        return f(1,0,0,maxChoosableInteger,desiredTotal,dp);
    }
};