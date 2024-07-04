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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node = head->next;
        int sum = 0;
        while(node){
            ListNode* curr = node;
            while(curr->val!=0){
                sum += curr->val;
                curr = curr->next;
            }
            node->val = sum;
            sum = 0;
            node->next = curr->next;
            node = node->next;
        }
        return head->next;
    }
};