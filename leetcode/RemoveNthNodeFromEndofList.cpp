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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return NULL;
        }
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nav = head;
        while (n--) {
            nav = nav->next;
        }
        
        while (nav) {
            prev = cur;
            cur = cur->next;
            nav = nav->next;
        }
        
        if (!prev) { // Head is being removed
            return head->next;
        }
        
        prev->next = cur->next;
        
        return head;
    }
};