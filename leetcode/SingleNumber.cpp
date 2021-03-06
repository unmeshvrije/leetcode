class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int n = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            n ^= nums[i];
        }
        
        return n;
    }
};