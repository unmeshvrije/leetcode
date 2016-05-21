class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int n = nums.size()-1;
        
        while(j <= n) {
            if (nums[j] < 1) {
                swap(nums[j], nums[i]);
                i++;
                j++;
            } else if (nums[j] > 1) {
                swap(nums[j], nums[n]);
                n--;
            } else {
                j++;
            }
        }
    }
};