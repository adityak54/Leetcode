class Solution {
public:
    int passThePillow(int n, int time) {
        int cycles = time/(n-1);
        int rem = time%(n-1);
        if(cycles&1) return n-rem;
        return rem+1;
    }
};