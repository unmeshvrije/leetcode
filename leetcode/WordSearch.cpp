class Solution {
    
    private:
    map<pair<int,int>, bool> visited;
    
public:

    void reinit_visited(vector<vector<char>>&board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                visited[pair<int,int>(i,j)] = false;
            }
        }
    }
    
    bool match(int i, int j, vector<vector<char>>&board, string word) {
        if (board.size() == 0 || board[0].size() == 0) {
            return false;
        }
        // we already matched the character on the board[i][j]
       // if (visited[pair<int,int>(i,j)] == true) {
            //cout << "Already matched" << endl;
       //     return false;
        //}
       // cout << "i = " << i << " , j = " << j;
        if (i>=0 && j>=0 && i < board.size() && j < board[0].size()) {
            if (board[i][j] == word[0]) {
                
               // visited[pair<int,int>(i,j)] = true;
                if  (word.size() == 1) {
                    return true;
                }
                
               // cout << " : Remaining string : " << word.substr(1) << " - nested calls: "<< endl;
               char ch = board[i][j];
               board[i][j] = '*';
                bool result = 
                match(i-1, j, board, word.substr(1)) ||
                match(i+1, j, board, word.substr(1)) ||
                match(i, j-1, board, word.substr(1)) ||
                match(i, j+1, board, word.substr(1));
                board[i][j] = ch;
                return result;
            }
        }
        //cout << " : return false" << endl;
        return false;
    }
    
    bool get_starting_positions(vector<vector<char>>&board, vector<pair<int,int>>& start, char ch) {
        // Return all the <i,j>s such that board[i][j] is the first letter of the word
        bool found = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                
                pair<int,int> address(i,j);
                //visited[address] = false;
                if (board[i][j] == ch) {
                    found = true;
                    start.push_back(address);
                }
            }
        }
        
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        // Empty string always exists in any board
        if (word.empty()) {
            return true;
        }
        
        // Non-empty cannot be found in the empty board
        if (board.empty()) {
            return false;
        }
        
        bool found;
        vector<pair<int,int>> starting_positions;
        found = get_starting_positions(board, starting_positions, word[0]);
        if (!found) {
            return false;
        }
        
        bool matched = false;
        for (int i = 0; i < starting_positions.size(); ++i) {
            //cout << starting_positions[i].first << " , " << starting_positions[i].second << endl;
            matched = match(starting_positions[i].first, starting_positions[i].second, board, word);
            if (matched) {
                return true;
            }
           // reinit_visited(board);
        }
        
        return matched;
    }
};