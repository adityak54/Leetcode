class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        bool chk=false;
        unordered_map<int,int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        for(auto &it: m){
            ans+=(it.second>>1);
            if(it.second&1) chk = true;
        }
        ans=ans<<1;
        if(chk) ans++;
        return ans;
    }
};