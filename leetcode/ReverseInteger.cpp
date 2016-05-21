class Solution {
public:
    int reverse(int x) {
        
        if (x == INT_MAX || x == INT_MIN) {
            return 0;
        }
        
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x *= -1;
        }
        
        long long ans = 0;
        while (x) {
            ans = ans*10 + (x%10);
            x /= 10;
        }
        
        if (ans > INT_MAX) {
            return 0;
        }
        
        return ans*sign;
    }
};