/**
 *    0 1 2
 *    -----
 * 0  1 2 3
 * 1  4 5 6
 * 2  7 8 9
*/
class Solution {
    private:
    void print_mat(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat.size(); ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int i = 0;
        int j = n-1;
        
        while (i < j) {
            for (int r = i, c = j; r < n-i-1 && c >= i+1; r++,c--) {
                int temp = matrix[i][r];    // temp = matrix[0][0]
                matrix[i][r] = matrix[c][i]; // matrix[0][0] = matrix[2][0]
                matrix[c][i] = matrix[j][c]; // matrix[2][0] = matrix[2][2]
                matrix[j][c] = matrix[r][j]; // matrix[2][2] = matrix[0][2];
                matrix[r][j] = temp;         // matrix[0][2] = temp
               // print_mat(matrix);
            }
            
            i++;
            j--;
        }
    }
};