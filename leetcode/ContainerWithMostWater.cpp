class Solution {
public:
    int maxArea(vector<int>& height) {
        int left  = 0;
        int right = height.size()-1;
        int max   = 0;
        
        while(left < right) {
            int area = (right-left) * ((height[left] < height[right]) ? height[left++] : height[right--]);
            max = (max > area) ? max : area;
        }
        
        return max;
    }
};