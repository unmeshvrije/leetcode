/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    int getLengthOfList(ListNode* head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    ListNode* reverseList(ListNode* &head, int m, int n) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* mov;
        for (int i = 1; i < m; ++i) {
            prev = prev->next;
        }
        ListNode* cur = prev->next;
        int len = n-m+1;
        while (--len && cur->next) {
            mov = cur->next;
            cur->next = mov->next;
            mov->next = prev->next;
            prev->next = mov;
        }
        
        return prev;
    }
    
    void displayList(ListNode* head) {
        while (head) {
            cout << head->val;
            if (head->next) {
                cout << "=>";
            }
            head = head->next;
        }
        cout << endl;
    }
    
    void mergeLists(ListNode* &head1, ListNode* &head2) {
        ListNode* nav1 = head1;
        ListNode* nav2 = head2;
        ListNode* cur;
        ListNode* last = NULL;
        
        while (nav2 && nav1) {
            cur = nav2->next;
            nav2->next = nav1->next;
            nav1->next = nav2;
            nav2 = cur;
            if (nav1->next) {
                if (nav1->next->next == NULL) {
                    last = nav1->next;
                }
                nav1 = nav1->next->next;
            } else {
                last = nav1;
                break;
            }
        }
        
        // In case of odd length list, we need to add the last element
        if (nav2) {
            last->next = nav2;
        }
    }
public:
    void reorderList(ListNode* head) {
        int n = getLengthOfList(head);
        if (n <= 2) {
            return;
        }
        
        ListNode* endOfList1 = reverseList(head, (n/2)+1, n);
        
        //displayList(head);
        //cout << endOfList1->val << endl;
        ListNode* head2 = endOfList1->next;
        endOfList1->next = NULL;
        
        mergeLists(head, head2);
        
    }
};