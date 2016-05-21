class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = n;
        for (int i = 0; i < n; ++i) {
            if (citations[i] < h) {
                --h;
            }
        }
        
        return h;
    }
};