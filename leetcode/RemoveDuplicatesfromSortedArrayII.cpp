class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        
        int j,index = 0;
        nums[index++] = nums[0];
        //nums[index++] = nums[1];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1] && i+1 < n && nums[i] == nums[i+1]) {
                continue;
            }
            nums[index++] = nums[i];
        }
        return index;
    }
};