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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        
        int leftMin = minDepth(root->left);
        int rightMin = minDepth(root->right);
        
        if (root->left == NULL) {
            return 1 + rightMin;
        }
        
        if (root->right ==  NULL) {
            return 1 + leftMin;
        }
        
        return 1 + std::min(leftMin, rightMin);
    }
};