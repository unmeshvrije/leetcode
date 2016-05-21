class Solution {
    private:
    
    bool isSafe(vector<string>& board, int row, int col) {
        
        // Check all elements to the left of col in this row
        for (int i = 0; i < col; ++i) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }
        
        // Check the left upper diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        // Check the left lower diagonal
        for (int i = row, j = col; i < board.size() && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    
    bool n_queen_util(vector<string> board, int n, int col, int& solutions) {
        if (col >= n) {
            solutions++;
            return true;
        }
        
        // Try to place the queen in each row
        for (int i = 0; i < n; ++i){
            if (isSafe(board, i, col)) {
                board[i][col] = 'Q';
                
                if (!n_queen_util(board, n, col+1, solutions)) {
                    board[i][col] = '.';
                }
            }
        }
        
        return false;
    }
public:
    int totalNQueens(int n) {
        string row(n, '.');
        vector<string> board = vector<string>(n);
        for (int i = 0; i < n; ++i) {
            board[i] = row;
        }
        
        int solutions = 0;
        n_queen_util(board, n, 0, solutions);
        return solutions;
    }
};