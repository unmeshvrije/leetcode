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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*>st;
        TreeNode *temp = root;
        int i = 0;
        
        if (root == NULL) {
            return 0;
        }
        
        st.push(root);
        while(1) {
            while (temp && temp->left) {
                st.push(temp->left);
                temp = temp->left;
            }
            
            if (st.empty()) {
                break;
            }
            
            temp = st.top();
            st.pop();
            ++i;
            if (i == k) {
                return temp->val;
            }
            
            if (temp->right) {
                st.push(temp->right);
                temp = temp->right;
            } else {
                temp = NULL;
            }
        }
    }
};