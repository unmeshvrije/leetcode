class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2, -1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target && range[0] == -1) {
                range[0] = i;
            }
            if (nums[i] != target && range[0] != -1 && range[1] == -1) {
                range[1] = i-1;
            }
        }
        
        if (range[0] != -1 && range[1] == -1) {
            range[1] = nums.size()-1;
        }
        return range;
    }
};