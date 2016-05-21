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
    
    void appendNode(ListNode* & head, ListNode* &tail, int val) {
        ListNode* newnode = new ListNode(val);
        
        if (head == NULL && tail == NULL) {
            head = tail = newnode;
            return;
        }
        
        tail->next = newnode;
        tail = newnode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        ListNode* nav1 = l1;
        ListNode* nav2 = l2;
        
        int a,b,c, carry = 0;
        while (nav1 && nav2) {
            a = nav1->val;
            b = nav2->val;
            c = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            appendNode(head, tail, c);
            nav1 = nav1->next;
            nav2 = nav2->next;
        }
        
        while (nav1) {
            a = nav1->val;
            c = (a + carry) % 10;
            carry = (a + carry) / 10;
            appendNode(head, tail, c);
            nav1 = nav1->next;
        }
        
        while (nav2) {
            b = nav2->val;
            c = (b + carry) % 10;
            carry = (b + carry) / 10;
            appendNode(head, tail, c);
            nav2 = nav2->next;
        }
        
        if (carry) {
            appendNode(head, tail, carry);
        }
        
        return head;
    }
};