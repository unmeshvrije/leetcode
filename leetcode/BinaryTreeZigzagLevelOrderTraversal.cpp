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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        //queue<TreeNode*> q;
        stack<TreeNode*> stackCurrentLevel;
        stack<TreeNode*> stackNextLevel;
        
        TreeNode* node;
        vector<vector<int>> result;
        vector<int> level;
        
        stackCurrentLevel.push(root);
        while (!stackCurrentLevel.empty()) {
            
            level.clear();
            while(!stackCurrentLevel.empty()) {
                node = stackCurrentLevel.top();
                stackCurrentLevel.pop();
                if (node) {
                    level.push_back(node->val);
                    if (node->left) {
                        stackNextLevel.push(node->left);
                    }
                    if (node->right) {
                        stackNextLevel.push(node->right);
                    }
                }
            }
            if (level.size() > 0) {
                result.push_back(level);
            }
            
            level.clear();
            while(!stackNextLevel.empty()) {
                node = stackNextLevel.top();
                stackNextLevel.pop();
                if (node) {
                    level.push_back(node->val);
                    if (node->right) {
                        stackCurrentLevel.push(node->right);
                    }
                    if (node->left) {
                        stackCurrentLevel.push(node->left);
                    }
                }
            }
            if(level.size() > 0) {
                result.push_back(level);
            }
        }
        
        return result;
    }
};