class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int currXor = arr[i];
            for(int j=i+1; j<n; j++){
                currXor ^= arr[j];
                if(currXor==0) ans+=j-i;
            }
        }
        return ans;
    }
};