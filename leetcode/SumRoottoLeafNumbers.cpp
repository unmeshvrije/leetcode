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
    void allPaths(TreeNode* root, vector<vector<int>>& result, vector<int> path) {
        if (root == NULL) {
            return;
        }
        
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
            return;
        }
        
        allPaths(root->left, result, path);
        allPaths(root->right, result, path);
    }
    // 1234
    int get_sum(vector<int>& vec) {
        int num = 0;
        for (int i = vec.size()-1, base = 1; i >= 0; i--, base = base*10) {
            num += (base * vec[i]);
        }
        return num;
    }
    
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> path;
        allPaths(root, result, path);
        
        int sum = 0;
        for (int i = 0; i < result.size(); ++i) {
            sum += get_sum(result[i]);
        }
        
        return sum;
    }
};