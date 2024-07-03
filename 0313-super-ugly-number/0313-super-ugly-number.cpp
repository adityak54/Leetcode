class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pointers(primes.size()), dp(n,INT_MAX);
        dp[0] = 1;
        
        for(int i=1; i<n; i++){
            int nextNumber = INT_MAX;
            for(int j=0; j<pointers.size(); j++){
                if(1LL*primes[j]*dp[pointers[j]]>INT_MAX) continue;
                int currOption = primes[j]*dp[pointers[j]];
                dp[i] = min(dp[i],currOption);
            }
            for(int j=0; j<pointers.size(); j++){
                if(1LL*primes[j]*dp[pointers[j]]>INT_MAX) continue;
                if(primes[j]*dp[pointers[j]]==dp[i]) pointers[j]++;
            }
        }
        // for(int i=0; i<n; i++) cout<<dp[i]<<" ";
        return dp[n-1];
    }
};