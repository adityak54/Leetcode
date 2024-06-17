class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        int i = sqrt(c);
        while(i){
            int rem = c-(i*i);
            int sqrtRem = sqrt(rem);
            if(sqrtRem*sqrtRem==rem) return true;
            i--;
        }
        return false;
    }
};