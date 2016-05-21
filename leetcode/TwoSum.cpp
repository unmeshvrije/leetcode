class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //std::sort(nums.begin(), nums.end());
        vector<int>result;
        int len = nums.size();
        
        for (int i = 0; i < len-1; ++i){
            int l = i;
            int r = len - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    result.push_back(l);
                    result.push_back(r);
                    return result;
                }
                r--;
            }
        }
        
        return result;
    }
};