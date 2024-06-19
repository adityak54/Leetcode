class Solution {
public:
    bool check(int mid, vector<int> &bloomDay, int m, int k){
        int cnt = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt==k){
                m--, cnt = 0;
            }
        }
        return m>0 ? false : true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()) return -1;
        int start = 1, end = 1e9,ans = -1;
        while(start<=end){
            int mid = start-(start-end)/2;
            if(check(mid,bloomDay,m,k)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};