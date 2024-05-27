class Solution {
public:
    int check(int mid, vector<int> &nums){
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>=mid) cnt++;
        }
        return cnt;
    }
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int start = 1, end = n;
        while(start<=end){
            int mid = start-(start-end)/2;
            int val = check(mid,nums);
            if(val==mid){
                return mid;
            }else if(val>mid){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return -1;
    }
};