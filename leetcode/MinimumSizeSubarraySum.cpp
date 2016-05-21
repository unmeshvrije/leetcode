class Solution {
public:

    int sum_of_subarray(int* sums, int i, int j) {
        if (i == 0) {
            return sums[j];
        }
        return sums[j]-sums[i-1];
    }
    
    bool checkSum(int target, int length, int* sums, int n) {
        for (int i = 0; i < n-(length-1); ++i) {
            int sum = sum_of_subarray(sums, i, i+length-1);
            if (sum >= target) {
                return true;
            }
        }
        return false;
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int* sums = new int[n];
        
        if (n == 0) {
            return 0;
        }
        
        sums[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i-1] + nums[i];
        }
        
        /*check for all possible lengths from 1 to n*/
        for (int i = 1; i <= n; ++i) {
            if (checkSum(s, i, sums, n)) {
                return i;
            }
        }
        
        return 0;
    }
};