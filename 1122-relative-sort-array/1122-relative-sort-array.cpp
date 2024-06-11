class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int,int> m;
        for(int i=0; i<arr1.size(); i++){
            m[arr1[i]]++;
        }
        for(int i=0; i<arr2.size(); i++){
            while(m[arr2[i]]){
                ans.push_back(arr2[i]);
                m[arr2[i]]--;
            }  
        }
        for(auto &it: m){
            while(it.second){
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
    }
};