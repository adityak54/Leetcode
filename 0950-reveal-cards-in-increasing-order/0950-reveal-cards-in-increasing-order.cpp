class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        sort(deck.begin(),deck.end());
        queue<int> q;
        for(int i=0;i<n;i++) q.push(i);
        int j=0;
        bool chk = false;
        while(!q.empty() && j<n){
            int ind = q.front();
            q.pop();
            if(chk){
                q.push(ind);
            }else{
                ans[ind] = deck[j++];
            }
            chk = !chk;
        }
        return ans;
    }
};