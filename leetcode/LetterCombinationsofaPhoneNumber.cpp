class Solution {
public:

    vector<char> get_chars(char from, int howMany) {
        vector<char> letters;
        for (int i = 0; i < howMany; ++i) {
            letters.push_back(from + i);
        }
        return letters;
    }
    
    void print_map(vector<char> telephone[10]) {
        for (int i = 0; i < 10; ++i) {
            cout << i << ": ";
            for (int j = 0; j < telephone[i].size(); ++j) {
                cout << telephone[i][j] << " ";
            }
            cout << endl;
        }
    }
    void init_map(vector<char> telephone[10] ) {
        telephone[0] = get_chars(' ', 0);
        telephone[1] = get_chars(' ', 0);
        telephone[2] = get_chars('a', 3);
        telephone[3] = get_chars('d', 3);
        telephone[4] = get_chars('g', 3);
        telephone[5] = get_chars('j', 3);
        telephone[6] = get_chars('m', 3);
        telephone[7] = get_chars('p', 4);
        telephone[8] = get_chars('t', 3);
        telephone[9] = get_chars('w', 4);
    }
    
    void letterCombUtil(int begin, string part, const string& digits, vector<char> telephone[10], vector<string>& result) {
        
        if (begin >= digits.size()) {
            return;
        }
        
        int index = digits[begin] - 48;
        
        for (int j = 0; j < telephone[index].size(); ++j) {
            string myPart = part;
            myPart += telephone[index][j];
            
            if (myPart.size() == digits.size()) {
                result.push_back(myPart);
            }
            
            letterCombUtil(begin+1, myPart, digits, telephone, result);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        vector<char> telephone[10];
        init_map(telephone);
        //print_map(telephone);
        letterCombUtil(0, "", digits, telephone, result);
        return result;
    }
};