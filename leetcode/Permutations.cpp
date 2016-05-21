class Solution {
public:

    void permuteUtil(vector<vector<int>>& result, vector<int>& nums, int nextIndex) {
        if (nextIndex == nums.size()) {
            result.push_back(nums);
        }
        
        for (int i = nextIndex; i < nums.size(); ++i) {
            swap(nums[i], nums[nextIndex]);
            permuteUtil(result, nums, nextIndex+1);
            swap(nums[i], nums[nextIndex]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteUtil(result, nums, 0);
        return result;
    }
};