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

    bool lineage(TreeNode *root, vector<TreeNode*>& ancestors, TreeNode *p) {
        if (root == NULL || p == NULL) {
            return false;
        }
        
        if (root == p) {
            // Node found
            return true;
        }
        
        bool found = (lineage(root->left, ancestors, p) || lineage(root->right, ancestors, p));
        if (found) {
            ancestors.push_back(root);
        }
        return found;
    }
    
    bool is_traceable(TreeNode *root, TreeNode *q) {
        if (root == NULL || q == NULL) {
            return false;
        }
        
        if (root == q) {
            return true;
        }
        return (is_traceable(root->left, q) || is_traceable(root->right, q));
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ancestors;
        
        // Check if p or q are traceable from each other
        if (is_traceable(p, q)) {
            return p;
        }
        
        if (is_traceable(q, p)) {
            return q;
        }
        
        // Find all ancestors of p;
        bool result = lineage(root, ancestors, p);
        if (!result) {
            cout << "No lineage found" << endl;
            return NULL;
        }
        
        cout << "ancestors : " << ancestors.size() << endl;
        for (int i = 0; i < ancestors.size(); ++i) {
            cout << ancestors[i]->val << endl;
            if (is_traceable(ancestors[i], q)) {
                return ancestors[i];
            }
        }
    }
};