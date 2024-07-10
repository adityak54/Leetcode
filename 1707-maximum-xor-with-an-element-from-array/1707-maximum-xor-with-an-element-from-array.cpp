struct TrieNode{
    TrieNode* list[2] = {NULL, NULL};
    bool containsKey(int bit){
        return list[bit]!=NULL;
    }
    void put(int bit, TrieNode* node){
        list[bit] = node;
    }
    TrieNode* get(int bit){
        return list[bit];
    }
};
class Trie{
    TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }
        void insert(int num){
            TrieNode* node = root;
            for(int i=31; i>=0; i--){
                int currBit = (num>>i)&1;
                if(!node->containsKey(currBit)){
                    node->put(currBit, new TrieNode());
                }
                node = node->get(currBit);
            }
        }
    
        int calculate(int num){
            TrieNode* node = root;
            int maxPossible = 0;
            for(int i=31; i>=0; i--){
                int currBit = (num>>i)&1;
                if(node->containsKey(1-currBit)){
                    maxPossible |= (1<<i);
                    node = node->get(1-currBit);
                }else{
                    if(!node->containsKey(currBit)) return -1;
                    node = node->get(currBit);
                }
            }
            return maxPossible;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        Trie t;
        vector<pair<int,pair<int,int>>> offlineQueries;
        for(int i=0; i<queries.size(); i++){
            offlineQueries.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        sort(nums.begin(),nums.end());
        int j = 0;
        for(int i=0; i<queries.size(); i++){
            int x = offlineQueries[i].second.first;
            int mx = offlineQueries[i].first;
            int ind = offlineQueries[i].second.second;
            while(j<nums.size()){
                if(nums[j]>mx) break;
                else t.insert(nums[j]);
                j++;
            }
            ans[ind]=t.calculate(x);
        }
        return ans;
    }
};