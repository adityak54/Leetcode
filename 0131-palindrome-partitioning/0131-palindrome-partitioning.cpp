class Solution {
private:
    bool isPalin(string &s){
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
    void f(int i,string curr,vector<string> &currPartitions,string &s,vector<vector<string>> &ans){
        int n = s.size();
        if(i==n){
            if(curr.empty())  ans.push_back(currPartitions);
            return;
        }
        for(int j=i;j<n;j++){
            curr.push_back(s[j]);
            if(isPalin(curr)){
                currPartitions.push_back(curr);
                f(j+1,"",currPartitions,s,ans);
                currPartitions.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> currPartitions;
        vector<vector<string>> ans;
        f(0,"",currPartitions,s,ans);
        return ans;
    }
};