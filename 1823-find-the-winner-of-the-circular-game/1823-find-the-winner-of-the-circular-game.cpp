class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n; i++) q.push(i);
        int ans = 0;
        while(!q.empty()){
            for(int i=0; i<k-1; i++){
                int safe = q.front();
                q.pop();
                q.push(safe);
            }
            ans = q.front();
            q.pop();
        }
        return ans;
    }
};