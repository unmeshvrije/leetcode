/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                ss << node->val << ",";

                q.push(node->left);
                q.push(node->right);
                
            } else {
                ss << "#" << ",";
            } 
        }
        
        cout << ss.str() << endl;
        
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        char * str = new char [data.length()+1];
        std::strcpy (str, data.c_str());
  
        queue<TreeNode*> q;
        TreeNode *root = NULL;
        
        str = strtok(str, ",");
        if (str != NULL) {
            int value = atoi(str);
            root = new TreeNode(value);
            q.push(root);
        }
        
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            TreeNode* left = NULL;
            TreeNode* right = NULL;
            
            str = strtok(NULL, ",");
            if(str != NULL) {
                if (strcmp(str, "#") != 0) {
                    int value = atoi(str);
                    left = new TreeNode(value);
                    q.push(left);
                }
            }
            
            str = strtok(NULL, ",");
            if(str!= NULL) {
                if (strcmp(str,"#") != 0) {
                    int value = atoi(str);
                    right = new TreeNode(value);
                    q.push(right);
                }
            }
            
            node->left = left;
            node->right = right;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));