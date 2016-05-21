/**
 * 0 1 2 3 4 5 6 7
 * 3 7 6 5 3 2 7 8
 * 
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) {
            return 0;
        }
        
        int l = 0;
        int r = n-1;
        int mid = (l + r)/2;
        
        while (1) {
            
            if (mid == 0) {
                if (nums[mid] > nums[mid+1]) {
                    return mid;
                }
                mid = mid+1;
            } else if (mid == n-1) {
                if (nums[mid] > nums[mid-1]) {
                    return mid;
                }
                mid = mid-1;
            } else {
                if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                    return mid;
                } else {
                    if (nums[mid-1] > nums[mid+1]) {
                        mid = mid-1;
                    } else {
                        mid = mid+1;
                    }
                }
            }
            
            
        }
        
        return -1;
    }
};