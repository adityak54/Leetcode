class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string s:logs){
            if(s[0]=='.' && s[1]=='.') ans = max(0,ans-1);
            else if(s[0]!='.') ans++;
        }
        return ans;
    }
};