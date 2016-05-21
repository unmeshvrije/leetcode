/**
 * 
 * Terminate when you find an element that is less than the last visited one
 * and store the length so far
*/

class Solution {
    
private:
  
    template <typename T>
    void print_matrix(vector<vector<T>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    int m,n;
    
    bool isValidIndex(int row, int col) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    
    int getMaxDistance(vector<vector<int>>&matrix, int x, int y, int cur, vector<vector<int>>& distance) {
        if (isValidIndex(x, y) && cur < matrix[x][y]) {
            return longestPathUtil(matrix, x, y, distance);
        }
        return 0;
    }
    
    int longestPathUtil(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& distance) {
        
        if (isValidIndex(row,col)) {
            if (distance[row][col] != -1) return distance[row][col];
            
            int cur = matrix[row][col];
            int maxDistance = 0;
            maxDistance = max(maxDistance, getMaxDistance(matrix, row, col-1, cur, distance));
            maxDistance = max(maxDistance, getMaxDistance(matrix, row, col+1, cur, distance));
            maxDistance = max(maxDistance, getMaxDistance(matrix, row-1, col, cur, distance));
            maxDistance = max(maxDistance, getMaxDistance(matrix, row+1, col, cur, distance));
            
            distance[row][col] = maxDistance + 1; //Include yourself
            return maxDistance+1;
        }
        return 0;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) {
            return 0;
        }
        n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        
        vector<vector<int>>dp(m, vector<int>(n, -1));
        
        int maxPathLength = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == -1) {
                    maxPathLength = max(maxPathLength, longestPathUtil(matrix, i, j, dp));
                } else {
                    maxPathLength = max(maxPathLength, dp[i][j]);
                }
            }
        }
        return maxPathLength;
    }
};