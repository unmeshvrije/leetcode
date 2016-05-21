class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while (nums[left] < target && nums[right] > target) {
            left++;
            right--;
        }
        
        while (nums[left] < target) {
            left++;
        }
            
        if (nums[left] == target) {
            return left;
        }
         
        while (nums[right] > target) {
            right--;
        }   
        if (nums[right] == target) {
            return right;
        }
            
        return -1;
    }
};