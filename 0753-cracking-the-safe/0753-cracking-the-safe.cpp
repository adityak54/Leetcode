class Solution {
public:
    string crackSafe(int n, int k) {
        string ans;
        for(int i=0; i<n; i++) ans.push_back('0');
        unordered_set<string> visited;
        visited.insert(ans);
        string prev = ans;
        for(int i = 0;i<pow(k,n);i++){
            prev.erase(0,1);
            for(int j = k-1;j>=0;j--){
                string now = prev + to_string(j);
                if(!visited.count(now)){
                    visited.insert(now);
                    ans += to_string(j);
                    prev += to_string(j);
                    break;
                }
            }
        }
        return ans;
    }
};