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
    ListNode* swapPairs(ListNode* head) {
        bool changeHead = true;
        ListNode* prev = NULL;
        ListNode* a = head;
        ListNode* b, *temp;
        
        while (a) {
            b = a->next;
            if (b) {
                if (changeHead) {
                    head = b;
                    changeHead = false;
                }
                temp = b->next;
                b->next = a;
                a->next = temp;
                if (prev) {
                    prev->next = b;
                }
                prev = a;
                a = temp;
            } else {
                break;
            }
        }
        
        return head;
    }
};