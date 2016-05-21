/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /**
  * 5->4->3->2->1
  * 4->5->1->2->3
  * 
  *  1 2 3 4
  * 
  *  3 4 1 2
  * 
  * 1 |3 1 2
  * 2 |2 3 1
  * 3 |1 2 3
  * 4 |3 1 2
  * 
 */
class Solution {
public:

    void display(ListNode* head) {
        while(head) {
            cout << head->val;
            if (head->next) {
                cout << "=>";
            }
            head = head->next;
        }
        cout << endl;
    }
    
    ListNode* reverseList(ListNode* head, int m, int n) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        
        if (m >= n) {
            return head;
        }
        
        for (int i = 0; i < m-1; ++i) {
            prev = prev->next;
        }
        int len = n-m+1;
        ListNode* cur = prev->next;
        ListNode* mov;
        
        while(--len && cur->next) {
            mov = cur->next;
            cur->next = mov->next;
            mov->next = prev->next;
            prev->next = mov;
        }
        
        return newHead->next;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *nav = head;
        int len = 0;
        
        if (head == NULL) {
            return NULL;
        }
        
        if (k == 0) {
            return head;
        }
        
        // Calculate length of the list
        while (nav) {
            len++;
            nav = nav->next;
        }
        
        if (len == 1) {
            return head;
        }
        
        if (k > len) {
            k = k %len;
        }
        
        head = reverseList(head, 1, len);
        //display(head);
        head = reverseList(head, 1, k);
        //display(head);
        head = reverseList(head, k+1, len);
        //display(head);
        return head;
    }
};