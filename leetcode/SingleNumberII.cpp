/**
 *
 * 1 2 3 4 2 3 1 4 2 1 4
 *
 * 001
 * 010
 * 011
 * 100
 * 010
 * 011
 * 100
 * 001
 * 010
 * 001
 * 100
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int one = 0;
        int two = 0;
        for (int i = 0; i < nums.size(); ++i) {
            one = (~two) & (one ^ nums[i]);
            two = (~one) & (two ^ nums[i]);
        }
        
        return one;
    }
};