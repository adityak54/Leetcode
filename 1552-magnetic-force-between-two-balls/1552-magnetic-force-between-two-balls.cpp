class Solution {
public:
    bool check(int mid, int m , vector<int> &position){
        int prev = position[0];
        m--;
        for(int i=1; i<position.size(); i++){
            if(position[i]-prev>=mid){
                prev = position[i];
                m--;
            }
        }
        return m>0 ? false : true;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 0, end = 1e9;
        int ans = 0;
        while(start<=end){
            int mid = start-(start-end)/2;
            if(check(mid,m,position)){
                start = mid+1;
                ans = mid;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};