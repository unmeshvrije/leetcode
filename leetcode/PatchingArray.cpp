/**
 * 1 5 10
 * n = 20
 * 
 * 
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int index = 0;
        int size = nums.size();
        long long target = 0;
        int patches = 0;
        while (target < n) {
            if (index < size && nums[index] <= target+1) {
                target += nums[index++];
            } else {
                patches++;
                target = 2*target + 1;
            }
        }
        
        return patches;
    }
};