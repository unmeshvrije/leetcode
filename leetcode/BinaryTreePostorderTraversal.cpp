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
    
    /**
     * 
     * The idea is to maintain two stacks. Main stack and Left stack.
     * Starting from root, push the node in the main stack and left stack and go to your right as far as the right goes.
     * Then pop elements from the "left" stack and repeat the logic for each node popped from the left stack.
     * At the end, Main stack will have the reverse of the postorder.
    */
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> post;
        stack<TreeNode*> main;
        stack<TreeNode*> left;
        
        if (root == NULL) {
            return post;
        }

        TreeNode *temp = root;
        
        while(temp) {
            main.push(temp);
            left.push(temp);
            temp = temp->right;
        }
        
        while(!left.empty()) {
            TreeNode *temp = left.top();
            left.pop();
            if (temp->left) {
                temp = temp->left;
                while(temp) {
                    main.push(temp);
                    left.push(temp);
                    temp = temp->right;
                }
            }
        }
        
        while(!main.empty()) {
            TreeNode* temp = main.top();
            main.pop();
            post.push_back(temp->val);
        }
    }
};