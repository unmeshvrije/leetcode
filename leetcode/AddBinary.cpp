class Solution {
public:

    string add(string a, string b) {
        stack<char> result;
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while (i >= 0) {
            
            int bit = a[i] - '0';
            if (j >= 0) {
                bit += b[j] - '0';
            }
            
            bit += carry;
            if (bit >= 2 ) {
                carry = 1;
                bit = bit%2;
            } else {
                carry = 0;
            }
            
            result.push('0'+bit);
            j--;
            i--;
        }
        
       // cout << "carry = " << carry << endl;
        
        if (carry) {
            result.push('0'+carry);
        }
        
        string sum = "";
        while (!result.empty()) {
            sum += result.top(); result.pop();
        }
        return sum;
    }
    
    string stripZeros(string str) {
        int i = 0;
        while (str[i] == '0') {
            i++;
        }
        if (i == str.size()) {
            // Only 0s
            return str;
        }
        return str.substr(i, string::npos);
    }
    
    string addBinary(string a, string b) {
        
        a = stripZeros(a);
        b = stripZeros(b);
        int len1 = a.size();
        int len2 = b.size();
        
        if (len1 > len2) {
            return add(a, b);
        } 
        return add(b, a);
    }
};