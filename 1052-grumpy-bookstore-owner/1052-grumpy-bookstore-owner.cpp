class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int curr = 0;
        for(int i=0; i<customers.size(); i++){
            if(!grumpy[i]) curr+=customers[i];
        }
        for(int i=0; i<minutes; i++){
            if(grumpy[i]) curr+=customers[i];
        }
        int start = 0, end = minutes, ans=curr;
        while(end<customers.size()){
            if(grumpy[start]) curr-=customers[start];
            if(grumpy[end]) curr+=customers[end];
            start++, end++;
            ans = max(ans,curr);
        }
        return ans;
    }
};