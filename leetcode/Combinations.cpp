class Solution {
public:
    void combineHelper(int begin, int n, vector<int> combination, vector<vector<int>>& result, int k) {
        
        combination.push_back(begin);
        if (combination.size() == k) {
            result.push_back(combination);
        }
        
        for (int i = begin+1; i <= n; ++i) {
            combineHelper(i, n, combination, result, k);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        vector<vector<int>> result;
        for (int i = 1; i <= n; ++i) {
            combineHelper(i, n, vec, result, k);
        }
        
        return result;
    }
};