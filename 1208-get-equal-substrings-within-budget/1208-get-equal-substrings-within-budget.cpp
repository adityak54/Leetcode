class Solution {
public:
    bool check(int mid, string &s, string &t, int maxCost){
        int n = s.size();
        int currCost = 0;
        for(int i=0;i<mid;i++){
            currCost+=abs(s[i]-t[i]);
        }
        int start = 0, end = mid;
        while(end<n){
            if(currCost<=maxCost) return true;
            currCost+=abs(s[end]-t[end])-abs(s[start]-t[start]);
            end++, start++;
        }
        return currCost<=maxCost;
    }
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int start = 1, end = n;
        int ans = 0;
        while(start<=end){
            int mid = start-(start-end)/2;
            if(check(mid,s,t,maxCost)){
                start = mid+1;
                ans = max(mid,ans);
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};