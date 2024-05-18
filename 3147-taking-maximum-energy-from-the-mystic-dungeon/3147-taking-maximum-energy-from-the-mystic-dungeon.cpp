class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<vector<int>> ans(k);
        for(int i=0;i<k;i++){
            int sum = 0;
            for(int j=i;j<n;j+=k){
                sum+=energy[j];
                ans[i].push_back(sum);
            }
        }
        int tot = INT_MIN;
        for(int i=0;i<k;i++){
            tot = max(tot, ans[i].back());
            for(int j=0;j<ans[i].size()-1;j++){
                tot = max(tot,(ans[i].back()-ans[i][j]));
                // cout<<ans[i][j]<<" ";
            }
            // cout<<endl;
        }
        return tot;
    }
};