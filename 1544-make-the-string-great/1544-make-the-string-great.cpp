class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        while(1){
            bool chk = false;
            int i=0,n=s.size();
            while(i<n){
                if(i!=n-1 && s[i]!=s[i+1] && tolower(s[i])==tolower(s[i+1])){
                    chk = true;
                    i+=2;
                }else{
                    ans.push_back(s[i]);
                    i++;
                }
            }
            if(!chk) return ans;
            s = ans;
            ans.clear();
        }
        return ans;
    }
};