class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<int,int> checks,checkt;
        for(int i=0;i<n;i++){
            if(checks.find(s[i])!=checks.end() && checks[s[i]]!=t[i]) return false;
            if(checkt.find(t[i])!=checkt.end() && checkt[t[i]]!=s[i]) return false;
            checks[s[i]] = t[i];
            checkt[t[i]] = s[i];
        }
        return true;
    }
};