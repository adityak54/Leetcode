class Solution {
public:
    bool isPalin(string &curr){
        int n = curr.size();
        for(int i=0;i<n/2;i++){
            if(curr[i]!=curr[n-i-1]) return false;
        }
        return true;
    }
    void f(int i, string curr, vector<string> &currPart,string &s,vector<vector<string>> &ans){
        int n = s.size();
        if(i==n){
            if(curr.empty()) ans.push_back(currPart);
            return;
        }
        curr.push_back(s[i]);
        f(i+1,curr,currPart,s,ans);
        if(isPalin(curr)){
            currPart.push_back(curr);
            f(i+1,"",currPart,s,ans);
            currPart.pop_back();
        }
        curr.pop_back();
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currPart;
        f(0,"",currPart,s,ans);
        return ans;
    }
};