/**
 * 
 * 0123
 * 0001
 * 102
 * 12.5
 * 1.5e+4
 * 12e+3
 * 
*/
class Solution {
public:

    int myAtoi(string str) {
        int n = str.size();
        if (n == 0) {
            return 0;
        }
        int sign = 1;
     
        int startpos = str.find_first_not_of(" \t");
        if (startpos != string::npos) {
            str = str.substr(startpos);
        }
        
        if (str[0] == '+') {
            sign = 1;
            str = str.substr(1);
        } else if (str[0] == '-') {
            sign = -1;
            str = str.substr(1);
        } else {
            if (!isdigit(str[0])) {
                return 0;
            }
        }
        
        string number = "";
        for (int i = 0; i < n; ++i) {
            if (!isdigit(str[i])) {
                break;
            }
            number += str[i];
        }
        
        cout << number << endl;
        
        int result = 0;
        for (int i = 0; i < number.size(); ++i) {
            
            int temp = result * 10 + number[i] - '0';
            if (temp/10 != result) {
                if (sign == 1) {
                    return INT_MAX;
                }
                return INT_MIN;
            }
            result = temp;
        }
        
        return sign * result;
    }
};