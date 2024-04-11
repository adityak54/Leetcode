class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k==n){return "0";}
        stack<char> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && k && s.top()>num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k) s.pop(),k--;
        string ans = "";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        while(ans.size()>1 && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};