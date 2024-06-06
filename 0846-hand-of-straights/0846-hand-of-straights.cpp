class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        map<int,int> m;
        for(auto card: hand){
            m[card]++;
        }
        for(auto &it: m){
            int val = it.first, freq = it.second;
            if(freq==0) continue;
            else if(freq<0) return false;
            for(int i=1; i<groupSize; i++){
                if(m.find(val+i)!=m.end()) m[val+i]-=freq;
                else return false;
            }
        }
        return true;
        
    }
};