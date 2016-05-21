class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        int m = nums.size();// number of bits
        int n = pow(2, m);  // number of elements in the PowerSet
        for (int i = 0; i < n; ++i) {
            result.push_back(vector<int>());
            for (int k = 0; k < m; ++k) {
                
                if (i & (1<<k)) {
                    result[i].push_back(nums[k]);
                }
            }
        }
        return result;
    }
};