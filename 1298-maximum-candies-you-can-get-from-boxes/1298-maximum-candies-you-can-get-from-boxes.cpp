class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0, n = status.size();
        queue<int> q;
        set<int> currKeys, currBoxes;
        for(int i=0;i<initialBoxes.size();i++){
            if(status[initialBoxes[i]]) {
                q.push(initialBoxes[i]);
            }else{
                currBoxes.insert(initialBoxes[i]);
            }
        }

        while(!q.empty()){
            int box = q.front();
            q.pop();
            ans+=candies[box];
            for(auto k:keys[box]) currKeys.insert(k);
            for(auto bx:containedBoxes[box]) currBoxes.insert(bx);
            for(auto it:currBoxes){
                if(currKeys.find(it)!=currKeys.end()){
                    currKeys.erase(it);
                    currBoxes.erase(it);
                    q.push(it);
                }else if(status[it]){
                    currBoxes.erase(it);
                    q.push(it);
                }
            }
        }
        
        return ans;
        
    }
};