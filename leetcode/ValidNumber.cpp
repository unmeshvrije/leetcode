/*
_0.1_ : true => space at the beginning and end is allowed
1_a : false => space is not allowed between characters
1_2 : false 
abc : false => Hexa decimal numbers are not allowed
1e20 
*/

class Solution {
    
    private:

public:

    bool isNumber(string s) {
        int n = s.size();
        bool number_began = false;
        bool exponent_began = false;
        bool float_began = false;
        bool space_began = false;
        bool number_sign_exists = false;
        bool sign_after_exponent = false;
        bool number_after_exponent = false;
        if (s.empty()) {
            return 0;
        }
        
        if (n == 1) {
            char ch = s[0];
            bool is_digit    = (ch >= '0' && ch <= '9');
            //bool is_exponent = (ch == 'e' || ch == 'E');
            return is_digit;
        }
        
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            bool is_digit    = (ch >= '0' && ch <= '9');
            bool is_space    = (ch == ' ');
            bool is_exponent = (ch == 'e' || ch == 'E');
            bool is_float    = (ch == '.');
            bool is_sign     = (ch == '+' || ch == '-'); // Sign of exponent or sign of number
            
            if (!is_digit && !is_space && !is_exponent && !is_float && !is_sign) {
                return false;
            } else {
                if (space_began && !is_space) {
                    cout << 1 ;
                    return false;
                }
            }
            
            if(exponent_began && is_digit) {
                number_after_exponent = true;
            }
            
            if (is_sign) {
                if (!number_began) {
                    if (number_sign_exists) {
                        cout << 2 ;
                        return false;
                    }
                    
                    if (i!=0 && s[i-1] == '.') {
                        return false;
                    }
                    
                    number_sign_exists = true;
                    continue;
                }
                
                if( s[i-1] != 'e' && s[i-1] != 'E') {
                    cout << 3 ;
                    return false;
                } else {
                    sign_after_exponent = true;
                }
            }
            
            if (is_exponent) {
                
                // Exponent cannot appear twice
                if (exponent_began || !number_began) {
                    cout << 4 ;
                    return false;
                }
                exponent_began = true;
                
                // There must be something numbers after e
                if (i+1 >= n) {
                    return false;
                }
            }
            
            if (is_float) {
                
                // Decimal point cannot appear twice
                if (float_began) {
                    cout << 5 ;
                    return false;
                }
                if (exponent_began) {
                    return false;
                }
                float_began = true;
            }
            
            if (!number_began && is_digit) {
                number_began = true;
            }
            
            if (is_space) {
                if (!number_began) {
                    if (i != 0 && (s[i-1] == '.' || s[i-1] == '+' || s[i-1] == '-')) {
                      return false;
                    }
                    continue;
                } else {
                  
                  space_began = true;
                }
            }
            
        }
        
        if (!number_began) {
            return false;
        }
        
        if (exponent_began && !number_after_exponent) {
            return false;
        }
        
        return true;
    }
};