class Solution {
public:
    int mySqrt(int x) {
        long long n = x;
        
        while (n*n > x) {
            n = (n + (x/n)) >> 1;
        }
        
        return n;
    }
};