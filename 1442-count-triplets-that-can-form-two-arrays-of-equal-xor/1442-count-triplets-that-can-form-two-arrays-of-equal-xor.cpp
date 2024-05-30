class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        unordered_map<int,int> countXor={{0,1}}, total;
        int currXor = 0;
        for(int i=0; i<n; i++){
            currXor ^= arr[i];
            ans+=countXor[currXor]*i-total[currXor];
            countXor[currXor]++, total[currXor]+=i+1;
        }
        return ans;
    }
};