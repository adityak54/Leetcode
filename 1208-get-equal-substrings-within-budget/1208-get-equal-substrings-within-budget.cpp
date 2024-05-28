class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0, currCost = 0,left=0;
        for(int i=0;i<n;i++){
            currCost+=abs(s[i]-t[i]);
            while(currCost>maxCost){
                currCost-=abs(s[left]-t[left]);
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};