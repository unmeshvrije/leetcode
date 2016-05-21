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
    void deleteNode(ListNode* node) {
        if (NULL == node) {
            return;
        }
        
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        free(temp);
    }
};