/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2);
        ans[0]=INT_MAX, ans[1]=-1;
        ListNode* node = head->next;
        int prevVal = head->val, cnt = 1;
        vector<int> criticalPoints;
        while(node){
            if(node->next && node->val>prevVal && node->val>node->next->val){
                criticalPoints.push_back(cnt);
            }
            
            if(node->next && node->val<prevVal && node->val<node->next->val){
                criticalPoints.push_back(cnt);
            }
            prevVal = node->val;
            node = node->next;
            cnt++;
        }
        for(int i=1; i<criticalPoints.size(); i++){
            ans[0] = min(ans[0], abs(criticalPoints[i]-criticalPoints[i-1]));
        }
        if(ans[0]==INT_MAX) ans[0] = -1;
        else ans[1] = criticalPoints.back()-criticalPoints[0];
        return ans;
    }
};