class Solution {
public:

    /**
     * A 65
     * Z 91
     * a 97
     *  -32
     *   65
     *   
    */
    bool is_alnum(char ch) {
        if (
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9') 
            ) {
                return true;
            }
            return false;
    }
    
    char to_lower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + 32;
        }
        return ch;
    }
    
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int n = s.size();
        int i = 0;
        int j = n - 1; 
        while (i<j) {
            // Skip all Non-alpha-numeric characters
            while (i < n && !is_alnum(s[i])) i++;
            while (j >=0 && !is_alnum(s[j])) j--;
            
           // cout << "i = " << i << " and j = " << j << endl;
            // Check if i and i are still within array
            if (i >= n || j < 0) {
                break;
            }
            
            char left = to_lower(s[i]);
            char right = to_lower(s[j]);
            
            if (left != right) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};