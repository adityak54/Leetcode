class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int currMax = 0;
        for(int k=0;k<=n;k++){
            while(!s.empty() && (k==n || heights[s.top()]>=heights[k])){
                int height = heights[s.top()];
                s.pop();
                int width = 0;
                if(s.empty()) width = k;
                else width=k-s.top()-1;
                currMax = max(currMax,height*width);
            }
            s.push(k);
        }
        return currMax;
    }
};