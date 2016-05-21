/**
 * Basic idea is simple. Maintain
 * follow->prev->temp pointer chain.
 * While temp and prev data is matching , delete temp.
 * We will have only one occurrence of the data (at prev),
 * Now use follow pointer to remove the prev and have follow->next point to temp (prev->next)
 * 
 * 
 * The trick is to use the Dummy head pointer so that head node can be removed
 * in case of duplicates
**/

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

    void print_list(ListNode *head) {
        while (head) {
            cout << head->val;
            if (head->next) {
                cout << "=>";
            }
            head = head->next;
        }
        cout << endl;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == NULL) {
            return NULL;
        }
        
        ListNode *oldHead = new ListNode(0);
        oldHead->next = head;
        
        ListNode *follow = oldHead;
        
        ListNode *prev = oldHead;
        ListNode *temp = head;
        
        while (temp) {
            follow = prev;
            prev = temp;
            temp = temp->next;
            
            if (temp) {
                bool duplicate_removed = false;    
                while (temp && prev->val == temp->val) {
                    
                    duplicate_removed = true;
                    // Delete temp
                    prev->next = temp->next;
                    free(temp);
                    temp = prev->next;
                }
                
                if (duplicate_removed) {
                    
                    follow->next = prev->next;
                    
                    if (prev) {
                        free(prev);
                    }
                    prev = follow;
                }
            }
           // print_list(oldHead->next);
        }
        
        return oldHead->next;
    }
};