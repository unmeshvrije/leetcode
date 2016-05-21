class Solution {
public:
/**
 * The idea behind the solution is as follows:
 * 
 * consider n = 4, there are 4! (24) possible permutations. We want to sequentially generate the permutations.
 * Note that all numbers in any permutation multiply up to 24
 * nums array
 * Values [1 2 3 4]
 * Indexes[0 1 2 3]
 * 
 * kth entry will actually be (k-1)th entry because of 0 based indexing.
 * consider k = 10
 * 
 * First we find the first digit in the expected permutation by doing (10 - 1) / 6 (note that 6 is coming from (n-1)! which in
 * this case is (4-1) ! = 3! = 3 X 2 = 6)
 * This gives us the index 1 (9/6).  1st element in the nums array is '2'.
 * 
 * Next step is intuitive, 
 * we remove the element from the nums array => [1 3 4]. The idea is to restrict the search in the block marked by double
 * pound signs (##)
 * we subtract (digit * f) i.e.  (1 * 6) from k (making k = 4) and then divide it (k-1) by (n-1)! this time by 2
 * giving us (4-1)/2 = 1. This gives us 3 
 * Now nums array becomes [1 4]
 * 
 * 
 * 0 | 1 2 3 4
 * 1 | 1 2 4 3
 * 2 | 1 3 2 4
 * 3 | 1 3 4 2
 * 4 | 1 4 2 3
 * 5 | 1 4 3 2
 * -----------
 * 6 | 2 1 3 4 ##
 * 7 | 2 1 4 3 ##
 * 8 | 2 3 1 4 ##
 * 9 | 2 3 4 1 ##
 * 10| 2 4 1 3 ##
 * 11| 2 4 3 1 ##
 * -----------
 * 12| 3 1 2 4
 * 13| 3 1 4 2
 * ...
 * ...
 * 
 * 
**/
  int fact(int n) {
      if (n == 1) {
          return 1;
      }
      return n * fact(n-1);
  }
  
  string getPermutation(int n, int k) {
        vector<int>nums;
        stringstream permutation;
        
        int f = fact(n);
        
        for (int i = 1; i <=n; ++i) {
            nums.push_back(i);
        }
        
        for (int bits = n; bits >= 1; --bits) {
            f /= bits;
            int digit = (k-1)/f;
            permutation << (nums[digit]);
            nums.erase(nums.begin() + digit);
            k = k - (digit * f);
        }
        
        return permutation.str();
    }
};