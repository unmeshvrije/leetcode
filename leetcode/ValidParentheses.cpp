class Solution {
public:
    bool isOpeningBracket(char ch) {
        return (ch == '(' || ch == '[' || ch == '{');
    }
    
    bool isValid(string s) {
        stack<char> brackets;
        for (int i = 0; i < s.size(); ++i) {
            if (isOpeningBracket(s[i])) {
                brackets.push(s[i]);
            } else if (s[i] == ')' && !brackets.empty()) {
                char opening = brackets.top();
                brackets.pop();
                if (opening != '(') {
                    return false;
                }
            } else if (s[i] == ']' && !brackets.empty()) {
                char opening = brackets.top();
                brackets.pop();
                if (opening != '[') {
                    return false;
                }
            } else if (s[i] == '}' && !brackets.empty()) {
                char opening = brackets.top();
                brackets.pop();
                if (opening != '{') {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        return brackets.empty();
    }
};