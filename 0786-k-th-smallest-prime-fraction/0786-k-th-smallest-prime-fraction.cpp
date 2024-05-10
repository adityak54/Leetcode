#define ppi pair<double,pair<int,int>>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        vector<int> ans(2);
        for(int i=0;i<n-1;i++){
            pq.push({double(double(arr[i])/double(arr[n-1])),{i,n-1}});
        }
        int req = 1;
        while(req<k){
            int i=pq.top().second.first;
            int j=pq.top().second.second-1;
            pq.pop();
            pq.push({double(double(arr[i])/double(arr[j])),{i,j}});
            req++;
        }
        ans[0]=arr[pq.top().second.first], ans[1]=arr[pq.top().second.second];
        return ans;
    }
};