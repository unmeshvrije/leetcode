/**
 * k = 1 , n = 7  O/P: [7]
 * k = 6, n = 6   O/P: []
 * k = 5, n = 1   O/P: []
 * 
*/
class Solution {
public:

    // 3,7,
    // 2,6,1 and 2,5,2 and so on
    //
    
    /**
     * 3,9
     * 
     * 2,8,1 | 2,7,2 | 2,6,3
     * 
    */
    void combinationSumUtil(vector<int> candidates, int start, int numsCount, int target, vector<int>&solution, vector<vector<int>>&result) {
        if (target < 0 || solution.size() > numsCount) {return;}
        if (target == 0 && solution.size() == numsCount) {
            result.push_back(solution);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            solution.push_back(candidates[i]);
            combinationSumUtil(candidates, i+1, numsCount, target - candidates[i], solution, result);
            solution.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> digits;
        vector<int> solution;
        vector<vector<int>> result;
        
        for (int i = 1; i <=9; ++i) {
            digits.push_back(i);
        }
        
        combinationSumUtil(digits, 0, k, n, solution, result);
        return result;
    }
};