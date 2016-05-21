class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        vector<int> result;
        unordered_map<int, bool> added;
        for (int i = 0; i < nums.size(); ++i) {
            counts[nums[i]]++;
            if (counts[nums[i]] > floor(nums.size()/3) && !added[nums[i]]) {
                result.push_back(nums[i]);
                added[nums[i]] = true;
            }
        }
        
        return result;
    }
};