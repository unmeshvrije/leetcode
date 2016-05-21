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
    ListNode* mergeTwoLists(ListNode* &l1, ListNode* &l2) {
        
        ListNode **npp = &l1;
        while(*npp && l2) {
            if ((*npp)->val > l2->val) {
                ListNode* temp = l2->next;
                l2->next = *npp;
                *npp = l2;
                l2 = temp;
            }
            npp = &((*npp)->next);
        }
        
        if (l2) {
            *npp = l2;
        }
        return l1;
    }
    
    ListNode* mergeRecurse(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        
        int mid = start + (end-start)/2;
        ListNode* l1 = mergeRecurse(lists, start, mid);
        ListNode* l2 = mergeRecurse(lists, mid+1, end);
        
        ListNode* res = mergeTwoLists(l1, l2);
        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }
        
        if (n == 1) {
            return lists[0];
        }
        
        return mergeRecurse(lists, 0, n-1);
        
    }
};