/**
 * Start moving from both ends
 * Add the difference between current height and maxHeight to the area, only if the current height is less than maxHeight
*/

class Solution {
    
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int low = 0;
        int high =  n-1;
        int maxHeight = -1;
        
        int *p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = height[i];
        }
        
        while (low <= high) {
            if (p[low] < p[high]) {
                if (p[low] > maxHeight) {
                    maxHeight = p[low];
                }
                area += maxHeight - p[low];
                low++;
            } else {
                if (p[high] > maxHeight) {
                    maxHeight = p[high];
                }
                area += maxHeight - p[high];
                high--;
            }
        }
        
        return area;
    }
};