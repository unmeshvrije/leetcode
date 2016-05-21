class Solution {
public:
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows < 1) {
            return result;
        }
        
        vector<int> first(1, 1);
        if (numRows >= 1) {
            result.push_back(first);
        }
        
        vector<int> second(2, 1);
        if (numRows >= 2) {
            result.push_back(second);
        }
        
        for (int i = 2; i < numRows; ++i) {
            vector<int> row(i+1);
            row[0] = row[i] = 1;
            for (int j = 1; j < i; ++j) {
                row[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(row);
        }
        
        return result;
    }
};