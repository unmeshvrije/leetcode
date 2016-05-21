/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    TreeLinkNode * find_next_from_sibling(TreeLinkNode* parent)
    {
        TreeLinkNode *nav = parent;
        
         while(nav = nav->next) {
                if (nav->left != NULL) {
                    return nav->left;
                }
                if (nav->right != NULL) {
                    return nav->right;
                }
        }
        
        return NULL;
    }
    
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        
        root->next = NULL;
        
        TreeLinkNode* leftMostNodeAtCurrentLevel = root;
        TreeLinkNode * leftMostNodeAtNextLevel = (root->left) ? root->left : root->right;
         while(leftMostNodeAtNextLevel){   
            while (leftMostNodeAtCurrentLevel) {
                
                if (leftMostNodeAtCurrentLevel->left) {
                    if (leftMostNodeAtCurrentLevel->right){
                        leftMostNodeAtCurrentLevel->left->next = leftMostNodeAtCurrentLevel->right;
                    } else{
                        leftMostNodeAtCurrentLevel->left->next = find_next_from_sibling(leftMostNodeAtCurrentLevel);
                    }
                }
                
                if (leftMostNodeAtCurrentLevel->right) {
                    leftMostNodeAtCurrentLevel->right->next = find_next_from_sibling(leftMostNodeAtCurrentLevel);
                }    
                
                leftMostNodeAtCurrentLevel = leftMostNodeAtCurrentLevel->next;
            }
            
            leftMostNodeAtCurrentLevel = leftMostNodeAtNextLevel;

            if (leftMostNodeAtCurrentLevel->left) {
                leftMostNodeAtNextLevel = leftMostNodeAtCurrentLevel->left;
            } else if (leftMostNodeAtCurrentLevel->right) {
                leftMostNodeAtNextLevel = leftMostNodeAtCurrentLevel->right;
            } else {
                leftMostNodeAtNextLevel = find_next_from_sibling(leftMostNodeAtCurrentLevel);
            }
        }
    }
};