class Solution {
public:
    bool f(int i, int cnto, int cntc, string &s, vector<vector<vector<int>>>& dp) {
        int n = s.size();
        if (i == n) return cnto == cntc;
        if (dp[i][cnto][cntc] != -1) return dp[i][cnto][cntc];
        if(cntc>cnto) return false;
        if (s[i] == '(') return dp[i][cnto][cntc] = f(i + 1, cnto + 1, cntc, s, dp);
        else if (s[i] == ')') return dp[i][cnto][cntc] = f(i + 1, cnto, cntc + 1, s, dp);
        int open = f(i + 1, cnto + 1, cntc, s, dp);
        int close = f(i + 1, cnto, cntc + 1, s, dp);
        int none = f(i + 1, cnto, cntc, s, dp);
        return dp[i][cnto][cntc] = open | close | none;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return f(0, 0, 0, s, dp);
    }
};
