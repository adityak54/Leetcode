class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> presentInAll(26,INT_MAX);
        for(int i=0;i<words.size();i++){
            vector<int> presentInCurr(26);
            for(auto ch: words[i]){
                presentInCurr[ch-'a']++;
            }
            for(int j=0;j<26;j++){
                presentInAll[j] = min(presentInAll[j],presentInCurr[j]);
            }
        }
        for(int i=0;i<26;i++){
            while(presentInAll[i]--){
                string temp = "";
                temp.push_back(char('a'+i));
                ans.push_back(temp);
            }
        }
        return ans;
    }
};