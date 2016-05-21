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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode **ppNode = &l1;
        
        while(*ppNode && l2) {
            if ((*ppNode)->val > l2->val) {
                ListNode* temp = l2->next;
                l2->next = *ppNode;
                *ppNode = l2;
                l2 = temp;
            }
            ppNode = &((*ppNode)->next);
        }
        
        if (l2) {
            *ppNode = l2;
        }
        
        return l1;
    }
};