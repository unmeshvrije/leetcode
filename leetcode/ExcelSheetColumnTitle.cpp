class Solution {
public:
    string convertToTitle(int n) {
        stack<char> s;
        while (n > 0) {
            int digit = n % 26;
            s.push('A' + (digit + 25)%26);
            if (digit == 0) {
                int cnt = n/26;
                if (cnt != 1) {
                    s.push('A' + (cnt-2));
                }
                break;
            }
            n /= 26;
        }
        
        string str;
        while(!s.empty()) {
            str += s.top(); s.pop();
        }
        
        return str;
    }
};