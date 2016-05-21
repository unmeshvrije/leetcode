class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (i+1 < heights.size() && heights[i] <= heights[i+1]) {
                continue;
            }
            
            int minHeight = heights[i];
            for (int j = i; j>=0; --j) {
                minHeight = min(minHeight, heights[j]);
                area = max(area, minHeight * (i-j+1));
            }
        }
        
        return area;
    }
};