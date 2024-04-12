class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int mxLeft = 0, mxRight = 0;
        int i=0, j=n-1;
        int ans = 0;
        while(i<=j){
            if(height[i]<=height[j]){
                mxLeft = max(mxLeft,height[i]);
                ans+=mxLeft-height[i];
                i++;
            }else{
                mxRight = max(mxRight,height[j]);
                ans+=mxRight-height[j];
                j--;
            }
        }
        return ans;
    }
};