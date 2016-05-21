class Solution {
    private:
    
    bool isVectorEqual(vector<int> v1, vector<int> v2) {
        if (v1.size() != v2.size()) {
            return false;
        }
        
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool exists(vector<vector<int>> rows, vector<int> r) {
        for (int i = 0; i < rows.size(); ++i) {
            if (isVectorEqual(rows[i], r)) {
                return true;
            }
        }
        return false;
    }
    
    void all_sums(vector<int>& candidates, vector<vector<int>>& result, vector<int> nums, int index, int target) {
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
           // if (!exists(result, nums)) {
                result.push_back(nums);
            //}
            return;
        }
        
        for (int i = index; i < candidates.size(); ++i) {
            if (i == index || candidates[i] != candidates[i-1]) {
                nums.push_back(candidates[i]);
                all_sums(candidates, result, nums, i+1, target-candidates[i]);
                nums.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> nums;
        all_sums(candidates, result, nums, 0, target);
        return result;
    }
};