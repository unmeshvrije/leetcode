/**
 * 
 * 100024102410282052
 * 
 * 123456579
 * 
 * 
*/

class Solution {
    
    private:
    
    int get_number_from_string(string num, int start_index, int num_digits) {
        if (num.empty()) {
            return 0;
        }
        
        int number;
        stringstream ss;
        ss << num.substr(start_index, num_digits);
        ss >> number;
        return number;
    }
    
    public:
    
    bool isAdditiveNumber(string num) {
        if (num.empty()) {
            return false;
        }
        
        int n = num.size();
     
        // Start with the first digit,
        int num1_digits = 1;
        int num2_digits = 1;
        
        int start_index_of_num1 = 0;
        int start_index_of_num2 = 0;
        int start_index_of_num3 = 0;

        stringstream ss;
        for (int num1_digits = 1; num1_digits < n; ++num1_digits) {
            
            if (num1_digits > 1 && num[start_index_of_num1] == '0') {
                break;
            }
            
            unsigned long long number1_orig = get_number_from_string(num, start_index_of_num1, num1_digits);
            
            for (int num2_digits = 1; num2_digits < n; ++num2_digits){
                
                unsigned long long number1 = number1_orig;
                start_index_of_num2 = start_index_of_num1+num1_digits;
                
                // Avoids the special case where 1023 => should return false,
                // because we are not considering leading 0s to be a part of the number
                if (num2_digits > 1 && num[start_index_of_num2] == '0') {
                    break;
                    // This would make previous loop increment its digits and the 0 will be the 
                    // part of the previous number
                }
                
                unsigned long long number2 = get_number_from_string(num, start_index_of_num2, num2_digits);
                
                unsigned long long number3;
                bool matched = false;
                
                if (start_index_of_num2 >= n) {
                    continue;
                }
                
               // cout << number1 << " " <<number2 << ": ";
                
                start_index_of_num3 = start_index_of_num2 + num2_digits;
                while(start_index_of_num3 < n) {
                    number3 = number1 + number2;
                    ss.str(std::string());
                    ss << number3;
                    int num3_digits = ss.str().size();
                   // cout << " Matching with " << ss.str() << endl;
                    if (num.substr(start_index_of_num3, num3_digits).compare(ss.str()) != 0) {
                        matched = false;
                        break;
                    } else {
                     //   cout << number1 << " + " << number2 << " = " << number3 << endl;
                       // cout << num.substr(start_index_of_num3, num3_digits) << " and " << ss.str() << endl;
                        matched = true;
                    }
                    start_index_of_num3 += num3_digits;
                    number1 = number2;
                    number2 = number3;
                }
                
               // cout << "n = " << n  <<"index: " << start_index_of_number << endl;
                // Loop completed normally with all comparisons successful
                if (matched) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};