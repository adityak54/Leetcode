class Solution {
public:
    void f(int i,string currAns,string curr,string s, set<string> &words,vector<string> &ans){
        int n = s.size();
        if(i==n){
            if(curr.empty()){
                currAns.pop_back();
                ans.push_back(currAns);
            }
            return;
        }
        curr.push_back(s[i]);
        f(i+1,currAns,curr,s,words,ans);
        if(words.find(curr)!=words.end()){
            currAns+=curr+" ";
            f(i+1,currAns,"",s,words,ans);
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> words(wordDict.begin(),wordDict.end());
        vector<string> ans;
        f(0,"","",s,words,ans);
        return ans;
    }
};