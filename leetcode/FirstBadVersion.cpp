// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        
        int lastBadVersion;
        
        while (low <= high) {
        
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)) {
                high = mid-1; 
                lastBadVersion = mid;
            } else {
                low = mid+1;
            }
        }
        
        return lastBadVersion;
    }
};