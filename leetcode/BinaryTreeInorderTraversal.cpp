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
    vector<int> inorderTraversal(TreeNode* root) {
        // Inorder is Left, data, right
        vector<int> inorder;
        
        stack<TreeNode*> s;
        TreeNode* temp = root;
        while (1) {
            while(temp) {
                s.push(temp);
                temp = temp->left;
            }
            
            if (s.empty()) {
                break;
            }
            
            TreeNode* node = s.top();
            s.pop();
            inorder.push_back(node->val);
            temp = node->right;
        }
        
        return inorder;
    }
};