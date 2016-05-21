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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) {
            return headA;
        }
        
        ListNode* navA = headA;
        ListNode* navB = headB;
        while (navA && navB && navA != navB) {
            navA = navA->next;
            navB = navB->next;
        }
        
        ListNode* shorterList;
        ListNode* longerList;
        
        int delta = 0;
        if (!navA && !navB) {
            // both lists are equal length
            // and no nodes match each other
            return NULL;
        } else if (!navB) {
            //headA is the longer list
            while (navA != navB) {
                navA = navA->next;
                delta++;
            }
            shorterList = headB;
            longerList = headA;
        } else {
            //headB is the longer list
            while (navA != navB) {
                navB = navB->next;
                delta++;
            }
            shorterList = headA;
            longerList = headB;
        }
        
        while(delta != 0) {
            longerList = longerList->next;
            --delta;
        }
        
        while (longerList != shorterList) {
            longerList = longerList->next;
            shorterList = shorterList->next;
        }
        
        return longerList;
    }
};