#define pi pair<int,int> 
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       int n= profits.size();
        vector<pi> cp(n);
        for (int i=0; i<n; i++) 
            cp[i] = {capital[i], profits[i]};

        sort(cp.begin(), cp.end());

        priority_queue<int> pq;

        int curr=0;
        for (int i = 0; i<k; i++) {
            for (curr; curr<n && cp[curr].first<=w; curr++) 
                pq.push(cp[curr].second);

            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            else break;
        }
        return w;
    }
};