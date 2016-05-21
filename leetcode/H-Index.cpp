/**
 * number of elements in the citations array (i.e. number of papers)
 * is the maximum h-index.
 * i.e. h = N (maximum h-index for a scientist having N papers)
 * 
 * Sort all the citations and keep on decreasing the h-index if any citation is less than N
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        std::sort(citations.begin(), citations.end());
        
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