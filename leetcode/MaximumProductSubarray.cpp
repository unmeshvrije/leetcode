class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if (nums.empty()) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int maxProd = nums[0];
        int pos = (nums[0] > 0) ? nums[0] : 0;
        int neg = (nums[0] < 0) ? nums[0] : 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            
            if (nums[i] == 0) {
                pos = 0;
                neg = 0;
            } else if (nums[i] > 0) {
                pos = max(nums[i], nums[i] * pos);
                neg = min(0, nums[i] * neg);
            } else {
                int temp = pos;
                pos = max(0, nums[i] * neg);
                neg = min(nums[i], nums[i] * temp);
            }
            
            maxProd = max(maxProd, pos);
        }
        
        return maxProd;
    }
};