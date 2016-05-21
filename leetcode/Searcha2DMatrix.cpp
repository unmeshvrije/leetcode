class Solution {
public:

    bool binSearch(vector<int>& arr, int start, int end, int num) {
        if (end < start) {
            return false;
        }
        
        int mid = start + (end-start)/2;
        if (arr[mid] == num) {
            return true;
        }
        
        if (num < arr[mid]) {
            return binSearch(arr, start, mid-1, num);
        } else {
            return binSearch(arr, mid+1, end, num);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (target <= matrix[i][n-1]) {
                return binSearch(matrix[i], 0, n-1, target);
            }
        }
        
        return false;
    }
};