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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = NULL;
        ListNode* bigHead = NULL;
        ListNode* smallCur = NULL;
        ListNode* bigCur = NULL;
        
        while (head) {
            if (head->val < x) {
                if (smallHead == NULL) {
                    smallHead = head;
                    smallCur = head;
                } else {
                    smallCur->next = head;
                    smallCur = head;
                }
            } else {
                if (bigHead == NULL) {
                    bigHead = head;
                    bigCur = head;
                } else {
                    bigCur->next = head;
                    bigCur = head;
                }
            }
            
            head = head->next;
        }
        
        if (!smallHead && !bigHead) {
            return head;
        }
        
        if (smallHead && !bigHead) {
            smallCur->next = NULL;
            return smallHead;
        }
        
        if (!smallHead && bigHead) {
            bigCur->next = NULL;
            return bigHead;
        }
        
        smallCur->next = bigHead;
        bigCur->next = NULL;
        return smallHead;
    }
};