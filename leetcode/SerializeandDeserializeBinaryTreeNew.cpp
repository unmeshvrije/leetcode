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
    
private:
    /**
    0 1 2 3 4 5 6 7 8
    a b c d , e f , g
    */
    vector<string> tokenize(string& str, char delimiter) {
        vector<string> tokens;
        int start = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == delimiter) {
                tokens.push_back(str.substr(start, i-start));
                start = i+1;
            }
        }
        return tokens;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        stringstream data;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                data << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                data << "#" << ",";
            }
        }
        
        return data.str();
    }

    TreeNode* make_newnode(string s) {
        if (s == "#") {
            return NULL;
        }
        TreeNode * newnode = new TreeNode();
        newnode->val = std::stoi(s);
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens = tokenize(data, ',');
        if (tokens.size() == 0) {
            return NULL;
        }
        
        queue<TreeNode*> q;
        TreeNode * root = make_newnode(tokens[0]);
        q.push(root);
        
        int index = 1;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            node->left = make_newnode(tokens[index++]);
            node->right = make_newnode(tokens[index++]);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
