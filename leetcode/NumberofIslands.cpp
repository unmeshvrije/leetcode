class Solution {
    
private:
    
    void fill(int row, int col, vector<vector<char>>& grid) {
        if (row >= 0 && row < grid.size() &&
            col >= 0 && col < grid[0].size() &&
            grid[row][col] == '1') {
                grid[row][col] = '2';
                fill(row, col-1, grid);
                fill(row, col+1, grid);
                fill(row-1, col, grid);
                fill(row+1, col, grid);
            }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        
        int cols = grid[0].size();
        if (cols == 0) {
            return 0;
        }
        
        int cntIslands = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    fill(i, j, grid);
                    ++cntIslands;
                }
            }
        }
        
        return cntIslands;
    }
};