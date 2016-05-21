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
    
    private:
    
    vector<TreeNode*> all_trees(vector<int>& roots, int start, int end) {
        
        vector<TreeNode*> result;
        
        if (start > end) {
            result.push_back(NULL);
            return result;
        }
        
        for (int i = start; i <= end; ++i) {
            
            vector<TreeNode*> leftTrees = all_trees(roots, start, i-1);
            vector<TreeNode*> rightTrees = all_trees(roots, i+1, end);
            
            for (auto lt : leftTrees) {
                for (auto rt: rightTrees){
                    TreeNode * root = new TreeNode(roots[i]);
                    root->left = lt;
                    root->right = rt;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> roots(n);
        for (int i = 1; i <= n; ++i) {
            roots[i-1] = i;
        }
        if (n == 0) {
            return vector<TreeNode*>();
        }
        
        return all_trees(roots, 0, n-1);
    }
};