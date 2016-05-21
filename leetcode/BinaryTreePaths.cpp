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

    void allPathsUtil(TreeNode* root, string path, vector<string>& result) {
        if (root == NULL) {
            return;
        }
        stringstream ss;
        if (path.compare("") == 0) {
            ss << root->val;
        } else {
            ss << path << "->" << root->val;
        }
        
        if (root->left == NULL && root->right == NULL) {
            result.push_back(ss.str());
            return;
        }
        
        path = string(ss.str());
        allPathsUtil(root->left, path, result);
        allPathsUtil(root->right, path, result);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL) {
            return result;
        }
        
        string paths = "";
        allPathsUtil(root, paths, result);
        return result;
    }
};