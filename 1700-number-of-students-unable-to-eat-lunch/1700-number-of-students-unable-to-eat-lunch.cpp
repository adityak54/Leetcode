class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(), ans = 0,cnt = 0;
        queue<int> q;
        for(int i=0;i<n;i++) q.push(students[i]);
        int j = 0;
        while(j<n && !q.empty()){
            int student = q.front();
            if(cnt==q.size()) break;
            q.pop();
            if(student==sandwiches[j]) j++,cnt=0,ans++;
            else{
                cnt++;
                q.push(student);
            }
        }
        return n-ans;
    }
};