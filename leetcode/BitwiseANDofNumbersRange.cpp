/**
 * Examples
 * 
 * 110 = 6
 * 111 = 7
 * ---
 * 110 = 6 (1 right bit is different)
 * 
 * 101 = 5
 * 110 = 6
 * 111 = 7
 * ---
 * 100 = 4 (2 right bits are different)
 * 
 * 
 * Keep on doing 1 RIGHT SHIFT for both m and n until they are equal.
 * We would have done k shifts. Now LEFT SHIFT m by k to get the answer
 * 
*/
class Solution {
  
public:
    int rangeBitwiseAnd(int m, int n) {
        int k = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            k++;
        }
        return m << k;
    }
};