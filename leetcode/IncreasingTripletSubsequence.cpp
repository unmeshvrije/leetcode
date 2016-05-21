class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        
        int min = nums[0];
        int mid = INT_MIN;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= min) {
                min = nums[i];
            } else {
                if (mid == INT_MIN || mid >= nums[i]) {
                    mid = nums[i];
                } else {
                    return true;
                }
            }
        }
        
        return false;
    }
};