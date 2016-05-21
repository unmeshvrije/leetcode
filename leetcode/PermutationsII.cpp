class Solution {
public:
    int n;
    
    void dfs(int dep, vector<int>& nums, vector<int> ans, vector<vector<int>>& result, vector<bool> &used) {
        if (n == dep) {
            result.push_back(ans);
            ans.clear();
            return;
        }
        for (int i = 0; i < n; ++i)
            if (!used[i] && (i == 0 || nums[i] != nums[i - 1] || used[i - 1])) {
                used[i] = true;
                ans.push_back(nums[i]);
                dfs(dep + 1, nums, ans, result, used);
                ans.pop_back();
                used[i] = false;
            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        n = nums.size();
        
        vector<bool> used;
        used.resize(n, false);
        vector<int> ans;
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        dfs(0, nums, ans, result, used);
        return result;
    }
};