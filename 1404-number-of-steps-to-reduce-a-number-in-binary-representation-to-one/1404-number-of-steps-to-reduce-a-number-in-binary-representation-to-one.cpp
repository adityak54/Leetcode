class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        int carry = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                if(!carry){
                    if(i!=0) ans+=2, carry=1;
                }else{
                    ans++;
                }
            }else{
                if(!carry) ans++;
                else ans+=2;
            }
        }
        return ans;
    }
};