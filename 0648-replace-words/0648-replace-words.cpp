class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans, curr="";
        set<string> dict(dictionary.begin(), dictionary.end());
        int i=0, n = sentence.size();
        while(i<n){
            curr.push_back(sentence[i]);
            if(dict.find(curr)!=dict.end()){
                ans+=curr;
                ans+=" ";
                curr.clear();
                while(i<n && sentence[i]!=' ') i++;
            }else if(sentence[i]==' '){
                ans+=curr;
                curr.clear();
            }
            i++;
        }
        if(!curr.empty()) ans+=curr;
        else ans.pop_back();
        return ans;
    }
};