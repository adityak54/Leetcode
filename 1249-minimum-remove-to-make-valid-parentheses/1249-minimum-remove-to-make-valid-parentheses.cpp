class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnto = 0, n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnto++;
            else if(s[i]==')' && cnto) cnto--;
            else if(s[i]==')' && !cnto) continue;
            st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            char element = st.top();
            st.pop();
            if(element=='(' && cnto){
                cnto--;
                continue;
            }
            ans.push_back(element);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};