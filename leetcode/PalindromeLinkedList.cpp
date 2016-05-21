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
    ListNode* getNthNode(ListNode* head, int i) {
        // 4
        while (--i && head) {
            head = head->next;
        }
        return head;
    }
    
    int getLength(ListNode* head) {
        int cnt = 0;
        while(head) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode* reverseList(ListNode* &head) {
        
        ListNode* newHead = new ListNode(0);
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
    
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head1 = head;
        ListNode* head2 = reverseList(slow->next);
       
       while (head1 && head2) {
           if (head1->val != head2->val) {
               return false;
           }
           head1 = head1->next;
           head2 = head2->next;
       }
       
       return true;
    }
};