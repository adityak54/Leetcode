class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int,int>> cnt;
        for(int i=0;i<len;i++){
            int cnt0 = 0, cnt1 = 0;
            for(int j=0;j<strs[i].size();j++){
                strs[i][j]=='0'?cnt0++:cnt1++;
            }
            cnt.push_back({cnt0,cnt1});
        }
        
        vector<vector<int>> curr(m+1,vector<int>(n+1,0));
        vector<vector<int>> ahead(m+1,vector<int>(n+1,0));

        for(int i=len-1;i>=0;i--){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int take = 0, notTake = 0;
                    int cnt0 = cnt[i].first, cnt1 = cnt[i].second;
                    if(cnt0<=j && cnt1<=k){
                        take = 1+ahead[j-cnt0][k-cnt1];
                    }
                    notTake = ahead[j][k];
                    curr[j][k] = max(take,notTake);
                }
            }
            ahead = curr;
        }
        return curr[m][n];
    }
};