class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> isSeat(101), isStudent(101);
        for(int i=0; i<seats.size(); i++){
            isSeat[seats[i]]++;
            isStudent[students[i]]++;
        }
        int ans=0, i=0, j=0;
        while(i<101 && j<101){
            if(isSeat[i] && isStudent[j]){
                ans+=abs(i-j);
                isSeat[i]--, isStudent[j]--;
            }
            else if(isSeat[i]) j++;
            else i++;
        }
        return ans;
    }
};