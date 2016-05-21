/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    void fill(vector<int>& nums, ListNode* head) {
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }
    
    TreeNode* make_tree(int low, int high, vector<int>& nums) {
        if (low > high) {
            return NULL;
        }
        
        int mid = low + (high-low) / 2;
        if (mid >= nums.size()) {
            return NULL;
        }
        
        TreeNode* newnode = new TreeNode(nums[mid]);
        newnode->left = make_tree(low, mid-1, nums);
        newnode->right = make_tree(mid+1, high, nums);
        return newnode;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        fill(nums, head);
        int n = nums.size();
        return make_tree(0, n, nums);
    }
};