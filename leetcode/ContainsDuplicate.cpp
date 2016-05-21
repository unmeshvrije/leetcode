class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int, bool> dup;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (dup[nums[i]]) {
                return true;
            } else {
                dup[nums[i]] = true;
            }
        }
        
        return false;
    }
};