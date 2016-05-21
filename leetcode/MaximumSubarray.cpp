class Solution {
public:
    
    int sumRange(vector<int>& sums, int i, int j) {
        if (i == 0) {
            return sums[j];
        }
        
        return sums[j] - sums[i-1];
    }
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        
        int maxSum  = nums[0];
        int temp = nums[0];
        for (int i = 1; i < n; ++i) {
            temp = max(nums[i], temp+nums[i]);
            maxSum = max(maxSum, temp);
        }
        
        return maxSum;
    }
};