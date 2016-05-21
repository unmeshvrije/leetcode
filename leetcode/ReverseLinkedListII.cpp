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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newHead = new ListNode(0),* pre = newHead;
        newHead->next = head;
        for(int i = 0; i < m-1; i++) pre = pre->next;
        int len = n - m + 1;
        ListNode* cur = pre->next;
        while(--len && cur->next){
            ListNode* mov = cur->next;
            cur->next = mov->next;
            mov->next = pre->next;
            pre->next = mov;
        }
        return newHead->next;
    }
};