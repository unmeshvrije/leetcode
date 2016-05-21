class Solution {
public:
    int titleToNumber(string s) {
        int col = 0;

        for (int i = s.size()-1, base = 1; i>=0; --i, base *= 26) {
            char ch = s[i];
            int n = ch - 'A' + 1;
            col += base * n;
        }
        
        return col;
    }
};