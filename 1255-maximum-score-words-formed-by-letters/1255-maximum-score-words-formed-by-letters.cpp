class Solution {
public:
    int f(int i, vector<string>& words, vector<int> &freq, vector<int>& score){
        int n = words.size();
        if(i==n) return 0;
        int notTake = f(i+1,words,freq,score);
        int take = 0, sc = 0;
        bool chk = true;
        for(int j=0;j<words[i].size();j++){
            if(freq[words[i][j]-'a']==0) chk = false;
            freq[words[i][j]-'a']--;
            sc+=score[words[i][j]-'a'];
        }
        if(chk) take = sc+f(i+1,words,freq,score);
        for(int j=0;j<words[i].size();j++){
            freq[words[i][j]-'a']++;
        }
        return max(take,notTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), m = letters.size();
        vector<int> freq(26);
        for(int i=0; i<m; i++){
            freq[letters[i]-'a']++;
        }
        return f(0,words,freq,score);
    }
};