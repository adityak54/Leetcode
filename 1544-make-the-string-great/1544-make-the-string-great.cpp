class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()!=s[i] && tolower(st.top())==tolower(s[i])){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};