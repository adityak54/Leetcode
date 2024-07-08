class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        bitset<100000> bs(1), mask;
        int j = 0;
        for(int i=0; i<n; i++){
            for(j; j<rewardValues[i]; j++){
                mask.set(j);
            }
            bs = bs|((mask&bs)<<rewardValues[i]);
        }
        
        for(int i=99999; i>=0; i--){
            if(bs.test(i)) return i;
        }
        return 0;
    }
};