/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    private:
    TreeNode* smallest;
    stack<TreeNode*> parents;
    bool first;
    
    TreeNode* getLeftMostNode(TreeNode* node) {
        TreeNode* temp = node;
        while (temp) {
            if (temp->left == NULL) {
                return temp;
            }
            parents.push(temp);
            temp = temp->left;
        }
        return NULL;
    }
    
public:
    BSTIterator(TreeNode *root) {
        smallest = getLeftMostNode(root);
        first = true;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        bool hasRight = false;
        if (smallest) {
            hasRight = (smallest->right)? true: false;
        } else {
            first = false;
        }
        
        return !parents.empty() || hasRight || first;
    }

    /** @return the next smallest number */
    int next() {
        if (first) {
            first = !first;
            return smallest->val;
        }
        
        if (smallest->right) {
            smallest = getLeftMostNode(smallest->right);
        } else {
            while (!parents.empty()) {
                TreeNode* trunk = parents.top();
                parents.pop();
                if (trunk->val > smallest->val) {
                    smallest = trunk;
                    break;
                }
            }
        }
        
        return smallest->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */