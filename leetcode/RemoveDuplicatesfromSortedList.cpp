/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = head;
        ListNode* cur = head;
        while (cur) {
            prev = cur;
            cur = cur->next;
            if(cur && prev->val == cur->val) {
                prev->next = cur->next;
                delete cur;
                cur = prev;
            }
        }
        
        return head;
    }
};