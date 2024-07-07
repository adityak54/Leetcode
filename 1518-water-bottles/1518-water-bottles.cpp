class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int emptyBottles = 0;
        while(numBottles){
            ans += numBottles;
            int newFilledBottles = (numBottles+emptyBottles)/numExchange;
            emptyBottles = (numBottles+emptyBottles)%numExchange;
            numBottles = newFilledBottles;
        }
        return ans;
    }
};