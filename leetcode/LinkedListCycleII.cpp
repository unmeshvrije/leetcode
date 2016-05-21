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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        if (head == NULL) {
            return NULL;
        }
        
        slow = slow->next;
        if (slow) {
            fast = slow->next;
        }
        
        // single element with next pointing to itself
        if (slow == fast) {
            return slow;
        }
        
        while (fast != NULL) {
            
            if(!fast->next) {
                return NULL;
            }
            
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                slow = head;
                while (slow != fast){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }
};