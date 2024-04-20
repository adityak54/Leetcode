class Solution {
    private:
    int delrow[4] = {0,0,1,-1};
    int delcol[4] = {1,-1,0,0};
public:
    pair<int,int> f(int row, int col, vector<vector<int>> &land,vector<vector<int>> &visited){
        int n = land.size(), m = land[0].size();
        visited[row][col] = 1;
        pair<int,int> ans;
        ans.first = row; ans.second = col;
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow<0 || ncol<0 || nrow==n || ncol==m) continue;
            if(!visited[nrow][ncol] && land[nrow][ncol]){
                pair<int,int> curr = f(nrow,ncol,land,visited);
                ans.first = max(ans.first,curr.first);
                ans.second = max(ans.second,curr.second);
            }
        }
        return ans;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> ans, visited(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && land[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i), temp.push_back(j);
                    pair<int,int> curr = f(i,j,land,visited);
                    temp.push_back(curr.first), temp.push_back(curr.second);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};