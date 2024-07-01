class Solution {
public:
    int f(int first, int second){
        int i=1, cnt = 0;
        while(1){
            if(first<i) return cnt;
            first -= i;
            cnt++, i++;
            
            if(second<i) return cnt;
            second -= i;
            cnt++, i++;
            
        }
        return cnt;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(f(red, blue), f(blue,red));
    }
        
};