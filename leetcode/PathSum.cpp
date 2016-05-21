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

    bool pathSumUtil(TreeNode* root, int sum, int partialSum) {
        if (root == NULL) {
            return false;
        }
        
        if (root->left == NULL && root->right == NULL) {
            if (partialSum + root->val == sum) {
                return true;
            }
            return false;
        } 
        
        partialSum += root->val;
        
        
        bool leftResult = false;
        bool rightResult = false;
        
        if (root->left) {
            leftResult = pathSumUtil(root->left, sum, partialSum);
        }
        
        if (root->right) {
            rightResult = pathSumUtil(root->right, sum, partialSum);
        }
        
        return leftResult || rightResult;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            if (sum != 0) {
                return false;
            }
        }
        
        int partialSum = 0;
        return pathSumUtil(root, sum, 0);
        
    }
};