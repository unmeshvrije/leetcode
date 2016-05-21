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
    
    unordered_map<int, int> inorder_index;
    
    TreeNode* insert(int num, TreeNode* root, vector<int>& inorder, TreeNode* lastAdded) {
        // num must be present in the inorder
        // Determine the correct position for num in the root
        TreeNode * newnode = new TreeNode(num);
        
       // cout << "handling " << num << endl;
        
        if (lastAdded && inorder_index[lastAdded->val] == inorder_index[num]+1) {
            lastAdded->left = newnode;
            return newnode;
        }
        
        if (lastAdded && inorder_index[lastAdded->val]+1 == inorder_index[num]) {
            lastAdded->right = newnode;
            return newnode;
        }
        
        TreeNode* nav = root;
        while(nav){
            if (inorder_index[num] < inorder_index[nav->val]) {
                if (nav->left == NULL) {
                    nav->left = newnode;
                    return newnode;
                } else {
                    nav = nav->left;
                }
            } else {
                if (nav->right == NULL) {
                    nav->right = newnode;
                    return newnode;
                } else {
                    nav = nav->right;
                }
            }
        }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       if (inorder.size() != preorder.size()) {
            return NULL;
        }
        
        int n = preorder.size();
        if (n == 0) {
            return NULL;
        }
        
        for (int i = 0; i < n; ++i) {
            inorder_index[inorder[i]] = i;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* last = root;
        for (int i = 1; i < n; ++i) {
            last = insert(preorder[i], root, inorder, last);
        }
        
        return root;
    }
};