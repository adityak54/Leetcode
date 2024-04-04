class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int n = s.size();
        int curr = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') curr++;
            else if(s[i]==')') curr--;
            ans = max(ans,curr);
        }
        return ans;
    }
};