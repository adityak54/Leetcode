class Solution {
    bool f(int i, int mx, vector<int> &sideLength, vector<int> &matchsticks){
        if(i==matchsticks.size()){
            return ((sideLength[0]==sideLength[1]) && (sideLength[2]==sideLength[3]) && (sideLength[0]==sideLength[2]));
        }
        for(int j=0; j<4; j++){
            if(sideLength[j]+matchsticks[i]>mx) continue;
            int k=j-1;
            for(; k>=0; k--) if(sideLength[k]==sideLength[j]) break;
            if(k!=-1) continue;
            sideLength[j] += matchsticks[i];
            if(f(i+1,mx,sideLength,matchsticks)) return true;;
            sideLength[j] -= matchsticks[i];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(),sum = 0;
        for(int i=0; i<n; i++) sum += matchsticks[i];
        if(sum%4!=0) return false;
        vector<int> sideLength(4);
        sort(matchsticks.begin(), matchsticks.end());
        return f(0,sum/4,sideLength,matchsticks);
    }
};