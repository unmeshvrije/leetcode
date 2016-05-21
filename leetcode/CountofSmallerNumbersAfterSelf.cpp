struct MyTreeNode {
    int val;
    int nLess;
    int nSame;
    MyTreeNode* left;
    MyTreeNode* right;
    MyTreeNode(int v): val(v) {
        nLess = 0;
        nSame = 1;
        left = right = NULL;
    }
};


void insert(MyTreeNode* root, int num, int& cntLess) {
    
    if (num < root->val) {
        root->nLess++;
        if (root->left == NULL) {
            root->left = new MyTreeNode(num);
        } else {
            insert(root->left, num, cntLess);
        }
    } else if (num > root->val) {
        cntLess += (root->nLess + root->nSame);
        if (root->right == NULL) {
            root->right = new MyTreeNode(num);
        } else {
            insert(root->right, num, cntLess);
        }
    } else {
        root->nSame++;
        cntLess += root->nLess;
    }
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n);
        
        if (n == 0) {
            return count;
        }
        
        count[n-1] = 0;
        MyTreeNode* root = new MyTreeNode(nums[n-1]);
        
        int cntLess;
        for (int i = n-2; i >= 0; --i) {
            cntLess = 0;
            insert(root, nums[i], cntLess);
            count[i] = cntLess;
        }
        
        return count;
    }
};