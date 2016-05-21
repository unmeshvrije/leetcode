/**
 * For every non-pound character, expect two more characters in the preOrder string
 * 
 * 
*/

class Solution {
    private:
    vector<string> tokenize(string str, char separator) {
        int begin = 0;
        vector<string> result;
        int index = str.find_first_of(separator);
        while (index != string::npos) {
            result.push_back(str.substr(begin, index-begin));
            begin = index+1;
            index = str.find_first_of(separator, index+1);
        }
        
        result.push_back(str.substr(begin));
        
        return result;
    }
    
public:
    bool isValidSerialization(string preorder) {
        vector<string> tokens = tokenize(preorder, ',');
        int nodes = 0;
        int cntTokens = tokens.size();
        for (int i = 0; i < cntTokens; ++i) {
            if (tokens[i].compare("#") == 0) {
                if (i != 0) {
                    nodes--;
                } else {
                    if (cntTokens > 1) {
                        return false;
                    }
                }
            } else {
                if (i != 0 && nodes == 0) {
                    return false;
                }
                if (i == 0) {
                    nodes += 2;
                } else {
                    nodes += 1;
                }
            }
        }
        
        if (nodes == 0) {
            return true;
        }
        return false;
    }
};