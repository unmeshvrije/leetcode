/**
 * 
 * Important observation here is that :
 * 
 * For any element a[i][j], all elements greater than a[i][j] can only be in row i+1 and column j+1
*/

class Solution {
public:

    bool binSearch(vector<int>& vec, int val, int start, int end) {
        if (val < vec[start] || val > vec[end]) {
            return false;
        }
        
        if (val == vec[start] || val == vec[end]) {
            return true;
        }
        
        int mid = floor((start+ end)/2);
        if (val == vec[mid]) {
            return true;
        }
        
        if (val < vec[mid]) {
            return binSearch(vec, val, start, mid);
        } else {
            return binSearch(vec, val, mid+1, end);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        
        for (int i = 0; i < rows; ++i) {
            if (binSearch(matrix[i], target, 0, cols-1)) {
                return true;
            }
        }
        
        return false;
    }
    
};