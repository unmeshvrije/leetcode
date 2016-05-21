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
    unordered_map<TreeNode*, int> leftMap;
    unordered_map<TreeNode*, int> rightMap;
    
    int robHelper(TreeNode* root, int flag) {
        if (root == NULL) {
            return 0;
        }
        
        if (flag == 1 && leftMap.find(root) != leftMap.end()) {
            return leftMap[root];
        }
        
        if (flag == 2 && rightMap.find(root) != rightMap.end()) {
            return rightMap[root];
        }
        
        if (flag == 1) {
            return leftMap[root] = robHelper(root->left, 2) + robHelper(root->right, 2) + root->val;
        } else {
            int sum1 = max(robHelper(root->left, 1), robHelper(root->left, 2));
            int sum2 = max(robHelper(root->right, 1), robHelper(root->right, 2));
            return rightMap[root] = sum1+sum2;
        }
    }
    
    int rob(TreeNode* root) {
        return max (robHelper(root, 1), robHelper(root, 2));
    }
};