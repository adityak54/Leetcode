#define pi pair<int,pair<int,int>>
class Solution {
    int dr[4] = {0,1,-1,0};
    int dc[4] = {1,0,0,-1};
    bool isValid(int row, int col, int n){
        if(row<0 || col<0 || row==n || col==n)  return false;
        return true;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return 0;
        vector<vector<int>> Mdist(n,vector<int>(n,INT_MAX));
        queue<pi> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) q.push({0,{i,j}}),Mdist[i][j]=0;
            }
        }

        while(!q.empty()){
            int currDist = q.front().first;
            int r = q.front().second.first, c = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i], nc = c+dc[i];
                if(isValid(nr,nc,n) && Mdist[nr][nc]>currDist+1){
                    Mdist[nr][nc] = currDist+1;
                    q.push({currDist+1,{nr,nc}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout << Mdist[i][j] << " ";
            cout<<endl;
        }
        vector<vector<int>> ans(n,vector<int>(n,INT_MIN));
        priority_queue<pi> pq;
        pq.push({Mdist[0][0],{0,0}});
        ans[0][0] = Mdist[0][0];
        while(!pq.empty()){
            int currDist = pq.top().first;
            int r = pq.top().second.first, c = pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==n-1) return currDist;
            for(int i=0;i<4;i++){
                int nr = r+dr[i], nc = c+dc[i];
                if(isValid(nr,nc,n)){
                    int currMin = min(currDist,Mdist[nr][nc]);
                    if(ans[nr][nc]<currMin){
                        ans[nr][nc] = currMin;
                        pq.push({currMin,{nr,nc}});
                    }
                }
            }
        }
        return ans[n-1][n-1];
    }
};