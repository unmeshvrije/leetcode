/**
 * 
 * Start scanning the string from the end
 * Stop when you encounter a space or start of the word
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool word_began = false;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (word_began) {
                    break;
                } else {
                    continue;
                }
            } else {
                len++;
                word_began = true;
            }
        }
        return len;
    }
};