/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * 
 * 1->2->3->4->5->6->7
 * p  q
 * 1->2->3->4->5->6->7
 * 
 * p
 * 1->3->5->7
 * q
 * 2->4->6
 * 
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        if (head->next == NULL) {
            return head;
        }
        
        ListNode *odd = head;
        ListNode *even = head->next, *join = head->next;
        
        while (odd->next || even->next) {

            if (odd->next){
                odd->next = odd->next->next;
                if (odd->next) {
                    odd = odd->next;
                }   
            }
            
            if (even->next) {
                even->next = even->next->next;
                if (even->next) {
                    even = even->next;
                }
            }
        }
        
        odd->next = join;
        
        return head;
    }
};