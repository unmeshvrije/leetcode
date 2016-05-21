/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 *   2
 *  / \
 * 3   4
 * 
 * 2->left->right = 2->right
 * 2->right = 2->left
 * 2->left = NULL
 * 
 */
class Solution {
public:

    pair<TreeNode*, TreeNode*> flatHelper(TreeNode* root) {
        if (root == NULL) {
            return pair<TreeNode*, TreeNode*>(NULL, NULL);
        }
        
        if (root->left == NULL && root->right == NULL) {
            return make_pair(root, root);
        }
        
        pair<TreeNode*, TreeNode*>  leftSubtree = flatHelper(root->left);
        pair<TreeNode*, TreeNode*> rightSubtree = flatHelper(root->right);
        
        if (leftSubtree.second) {
            (leftSubtree.second)->right = rightSubtree.first;
            root->right = leftSubtree.first;
            root->left = NULL;
            if (!rightSubtree.second) {
                return make_pair(root, leftSubtree.second);
            }
            return make_pair(root, rightSubtree.second);
        }
        
        root->left = NULL;
        root->right = rightSubtree.first;
        return make_pair(root, rightSubtree.second);
    }
    
    void flatten(TreeNode* root) {
        // Node's left subtree's last nodes's right = Node's right
        // Node's right  = Node's left subtree
        // Node's left = NULL
        if (root == NULL) {
            return;
        }
        
        flatHelper(root);
    }
};