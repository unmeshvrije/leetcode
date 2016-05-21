class Solution {
public:
    void print_grid(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        
        vector<vector<int>> sums(rows, vector<int>(cols, 0));
        
        int m = rows-1;
        int n = cols-1;
        sums[m][n] = grid[m][n];
        
        for (int i = n-1; i >= 0; --i) {
            sums[m][i] = grid[m][i] + sums[m][i+1];
        }
        
        for (int i = m-1; i >= 0; --i) {
            sums[i][n] = grid[i][n] + sums[i+1][n];
        }
        
       // print_grid(sums);
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                sums[i][j] = min (sums[i][j+1] + grid[i][j], sums[i+1][j] + grid[i][j]);
            }
        }
        
        return sums[0][0];
    }
};