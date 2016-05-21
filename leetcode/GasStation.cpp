/**
 * Important observation is that 
 * After the round, the sum of differences between costs and gas must be positive.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = -1, max_diff = INT_MIN, total = 0;
        for (int i = cost.size()-1; i >= 0; --i){
            total += gas[i] - cost[i];
            if (total >= max_diff) {
                max_diff = total;
                index = i;
            }
        }
        
        if (total >= 0) {
            return index;
        }
        
        return -1;
    }
};