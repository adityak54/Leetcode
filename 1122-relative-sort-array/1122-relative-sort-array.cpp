class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> checker(1001,-1);
        for(int i=0; i<arr2.size(); i++){
            checker[arr2[i]] = i;
        }
        for(int i=0; i<=1000; i++){
            if(checker[i]==-1) checker[i] = arr2.size()+i;
        }
        sort(arr1.begin(),arr1.end(), [&](int x, int y){
            return checker[x]<checker[y];
        });
        return arr1;
    }
};