class Solution {
public:
    int find_leftmost_zero(vector<int>&nums, int index) {
        while (index >= 0) {
            if (nums[index] != 0) {
                break;
            }
            index--;
        }
        return index+1;
    }
    
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                int swapIndex = find_leftmost_zero(nums, i-1);
                if (i != swapIndex) {
                    // Do swap
                    nums[swapIndex] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
};