class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size(), ans = INT_MAX;
        set<string> s(deadends.begin(),deadends.end());
        unordered_map<string,bool> m;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while(!q.empty()){
            string currString = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(s.find(currString)!=s.end()) continue;
            if(currString==target) ans =  min(ans,steps);
            for(int i=0;i<4;i++){
                string temp1 = currString, temp2 = currString;
                
                //increment
                if(temp1[i]=='9') temp1[i]='0';
                else temp1[i]++;
                if(!m[temp1]) m[temp1]=1, q.push({temp1,steps+1});
                
                //decrement
                if(temp2[i]=='0') temp2[i]='9';
                else temp2[i]--;
                if(!m[temp2]) m[temp2]=1, q.push({temp2,steps+1});
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};