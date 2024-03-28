class Solution {
public:
    int prime = 1e7+7;
    string longestDupSubstring(string &s) {
        int n = s.size();
        vector<int> roll(n);
        roll[0] = 1;
        for(int i=1;i<n;i++) roll[i] = (roll[i-1]*26)%prime;
        string ans = "";
        int low = 1, high = n-1;
        map<int,vector<int>> m;
        while (low <= high) {
            int mid = low - (low - high) / 2;
            int start = 0,end = mid;
            bool check = false;
            int currVal = 0;
            for(int i=0;i<end;i++){
                currVal = ((currVal*26)+(s[i]-'a'))%prime;
            }
            while(end<=n){
                if(m.find(currVal)!=m.end()){
                    for(auto index : m[currVal]){
                        if(s.substr(index,mid)==s.substr(start,mid)){
                            check = true;
                            ans = s.substr(index,mid);
                            break;
                        }
                    }
                }
                if(check) break;
                m[currVal].push_back(start);
                if(end==n) break;
                currVal=((currVal-((roll[mid-1]*(s[start]-'a'))%prime))+prime)%prime;
                currVal = (currVal*26+(int(s[end]-'a')))%prime;
                start++, end++;
            }
            if (check) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            m.clear();
        }
        return ans;
    }
};
