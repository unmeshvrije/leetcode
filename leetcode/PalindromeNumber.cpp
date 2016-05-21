class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int num = x;
        stack<int> digits;
        while(num) {
            int r = num % 10;
            num /= 10;
            digits.push(r);
        }
        
        int reverse = 0;
        int base = 1;
        while(!digits.empty()) {
            int r = digits.top(); 
            digits.pop();
            reverse += r* base;
            base *= 10;
        }
        cout << reverse << endl;
        return reverse == x;
    }
};