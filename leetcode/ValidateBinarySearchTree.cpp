/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // Crazy test cases like INT_MIN and INT_MAX
    // Check [1,1] , [0,-1] , [1,null,1] and so on
    bool isValidNode(TreeNode* root, long long int min, long long int max) {
        if (!root) {
            return true;
        }
        
        if (!(min < root->val && root->val < max)) {
                return false;
            
        }
        
        return isValidNode(root->left, min, root->val) && isValidNode(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        unsigned long long int min = 1<<63;
        unsigned long long int max = ~(min);
        
        if (root == NULL) {
            return true;
        }
        
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        
        return isValidNode(root, (unsigned long long int)1<<63, ~((unsigned long long int)1<<63));
    }
};