/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    
    private:
    std::map<RandomListNode*, RandomListNode*> address;
    
    RandomListNode* get_node(RandomListNode *temp) {
        
        if (temp == NULL) {
            return NULL;
        }
        RandomListNode *newnode;
        
        if (address.find(temp) == address.end()) {
            newnode = new RandomListNode(temp->label);
            address[temp] = newnode;
        } else {
            newnode = address[temp];
        }
        
        return newnode;
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode *temp = head;
        
        while(temp) {
            //newnode
            RandomListNode* newnode = get_node(temp);
            RandomListNode* next = get_node(temp->next);
            RandomListNode* random = get_node(temp->random);
            
            if (newnode) {
                newnode->next = next;
                newnode->random = random;
            }
            
            temp = temp->next;
        }
        
        return address[head];
    }
};