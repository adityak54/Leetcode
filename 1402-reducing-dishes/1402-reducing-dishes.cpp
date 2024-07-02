class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0;
        for(int i=0; i<n; i++){
            int currSum = 0, currTime = 1;   
            for(int j=i; j<n; j++){
                currSum += satisfaction[j]*currTime;
                currTime++;
            }
            ans = max(ans,currSum);
        }
        return ans;
    }
};