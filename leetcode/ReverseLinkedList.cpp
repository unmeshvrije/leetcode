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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* cur = prev->next;
        ListNode* mov;
        while (cur->next) {
            mov = cur->next;
            cur->next = mov->next;
            mov->next = prev->next;
            prev->next = mov;
        }
        
        return newHead->next;
    }
};