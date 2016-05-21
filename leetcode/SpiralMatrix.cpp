class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        int m = matrix.size();
        if (m == 0) {
            return result;
        }
        
        int n = matrix[0].size();
        int mn = min(m,n);
        
        int row, col;
        
        int layer = 0; // Cover row 0, column 0 etc.
        
        while (layer < ((mn+1)/2) ) {
            row = layer;
            col = layer;
            for (int i = col ; i < n-layer; ++i) {
                if (row < m && i < n) {
                    result.push_back(matrix[row][i]);
                }
            }
            
            col = (n-layer)-1;
            for (int i = row+1; i < m-layer; ++i) {
                if (i < m && col >=0 && col < n) {
                    result.push_back(matrix[i][col]);
                }
            }
            
            row = (m-layer)-1;
            for (int i = (n-layer)-2; i >= layer && row > layer; --i) {
                if (row >=0 && row < m && i >= 0 && i < n) {
                    result.push_back(matrix[row][i]);
                }
            }
            
            col = layer;
            for (int i = (m-layer)-2; i > layer && col < (n-layer)-1; --i) {
                if (row >=0 && row < m && col < n) {
                    result.push_back(matrix[i][col]);
                }
            }
            
            layer++;
        }
        
        return result;
    }
};