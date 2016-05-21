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

    ListNode* remove_nth_node(ListNode **head, int n){
        if (head == NULL || *head == NULL || n <=0 ) {
            return NULL;
        }
        
        ListNode *prev = NULL, *temp = *head;
        for (int i = 1; i < n; ++i) {
            // n > len(list)
            if (temp == NULL) {
                return NULL;
            }
            prev = temp;
            temp = temp->next;
        }
        
        ListNode* newnode = new ListNode(temp->val);
        
        if (prev) {
            prev->next = temp->next;
        } else {
            (*head) = temp->next;
        }
        
        free (temp);
        return newnode;
    }
    
    int get_length_of_list(ListNode *head){
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    void print_list(ListNode *head) {
        while(head) {
            cout << head->val;
            if (head->next) {
                cout << "=>";
            }
            head = head->next;
        }
        cout << endl;
    }
    
    void insert_node_into_list(ListNode **head, ListNode **node, int n) {
        if (head == NULL || node == NULL || *head == NULL || *node == NULL) {
            return;
        }
        
        if ((*head)->val >= (*node)->val) {
            (*node)->next = *head;
            *head = *node;
            return;
        }
        
        ListNode* temp = *head, *prev = *head;
        int i = 1;
        while (temp && temp->val < (*node)->val) {
            prev = temp;
            temp = temp->next;
            i++;
            if (i >= n) {
                break;
            }
        }
        
        (*node)->next = prev->next;
        prev->next = *node;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        int len = get_length_of_list(head);
        
        //First element is assumed to be sorted
        for (int i = 2; i <= len; ++i) {
            
            ListNode* node = remove_nth_node(&head, i);
            //cout << node->val << " removed" << endl;
            //print_list(head);
            if (node) {
                // Try to insert this node only until index i
                // At any point, the list [0..i] is sorted and not further
                insert_node_into_list(&head, &node, i);
              //  cout << node->val << " inserted" << endl;
            //    print_list(head);
                //cout << "===================" << endl;
            } else {
                cerr << "Could not remove node";
            }
        }
        
        return head;
    }
};