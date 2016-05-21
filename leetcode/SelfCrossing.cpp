/**
 *  __ __ __
 * |        |
 * |        |
 * 
*/
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() == 0) {
            return false;
        }
        
        for (int i = 0; i < x.size(); ++i) {
        
            //          south  <= north  && west <= east
            if (i>=3 && x[i-1] <= x[i-3] && x[i-2] <= x[i]) {
                return true;
            }
            
            //           east == west   && North+prevNorth >= South
            if (i>=4 && x[i-1] == x[i-3] && x[i]+x[i-4] >= x[i-2]) {
                return true;
            }
            //
            if (i>=5 && x[i]+x[i-4] >= x[i-2] && x[i-1]+x[i-5] >= x[i-3] && x[i-2] >= x[i-4] && x[i-3] >= x[i-1]) {
                return true;
            }
        }
        return false;
    }
};