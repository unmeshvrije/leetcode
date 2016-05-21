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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        int currentLevel = 1;
        int nextLevel = 0;
        vector<int> level;
        vector<vector<int>> result;
        stack<vector<int>> s;
        
        if (root) {
            q.push(root);
        }
        
        while(!q.empty()) {
            
            TreeNode* node = q.front(); q.pop();
            currentLevel--;
            
            level.push_back(node->val);
            if (node->left) {
                q.push(node->left);
                nextLevel++;
            }
            if (node->right) {
                q.push(node->right);
                nextLevel++;
            }
            cout << node->val << " ";
            
            if (currentLevel == 0) {
                s.push(level);
                level.clear();
                currentLevel = nextLevel;
                nextLevel = 0;
            }
        }
        
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        
        return result;
    }
};