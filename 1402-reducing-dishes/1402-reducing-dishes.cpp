class Solution {
public:
    int f(int i, int currSize, vector<int> &satisfaction, vector<vector<int>> &dp){
        int n = satisfaction.size();
        if(i==n) return 0;
        if(dp[i][currSize]!=INT_MIN) return dp[i][currSize];
        int take = 0, notTake = 0;
        take = currSize*satisfaction[i] + f(i+1,currSize+1,satisfaction,dp);
        notTake = f(i+1,currSize,satisfaction,dp);
        return dp[i][currSize] = max(take,notTake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n,vector<int>(n+1,INT_MIN));
        return f(0,1,satisfaction,dp);
    }
};