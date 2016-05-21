class Solution {
public:
    void reverseWords(string &s) {
        stack<char> words;
        stack<char> reverse;
        
        cout << "before trim: [" << s <<"]" << endl;
        
        s.erase(0, s.find_first_not_of(' '));  //prefixing spaces
        s.erase(s.find_last_not_of(' ')+1);     // Suffixing spaces

        cout << "after trim: [" << s <<"]" << endl;
        for (int i = 0; i < s.size(); ++i) {
            words.push(s[i]);
        }
        
        string result = "";
        
        while(!words.empty()) {
            char ch = words.top();
            words.pop();
            if (ch == ' ') {
                while(words.top() == ' ') {
                    words.pop();
                }
                if (!reverse.empty()){
                    while (!reverse.empty()) {
                        result += reverse.top();
                        reverse.pop();
                    }
                    
                    // If it is not the last word, then add space
                    if (!words.empty()) {
                        result += ' ';
                    }
                }
            } else {
                //cout << "pusing " << ch << endl;
                reverse.push(ch);
            }
        }
        
        while (!reverse.empty()) {
            result += reverse.top();
            reverse.pop();
        }
        
        s = result;
    }
};