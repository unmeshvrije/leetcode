class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        if (num >= 0) {
            result[0] = 0;
        }
        if (num >= 1) {
            result[1] = 1;
        }
        
        for (int i = 2; i <= num; ++i) {
            if (i%2 == 0) {
                result[i] = result[i/2];
            } else {
                result[i] = result[i/2]+1;
            }
        }
        
        return result;
    }
};