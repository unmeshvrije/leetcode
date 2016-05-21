class Solution {
public:

    // Min[j] = Min[j-val[i] + 1

    int numSquares(int n) {
        vector<int>Min(n+1);
        
        for (int i = 1; i < Min.size(); ++i) {
            Min[i] = INT_MAX;
        }
        
        Min[0]= 0;
        for (int i = 1; ; ++i) {
            int square = i*i;
            for (int j = 1; j <=n; ++j) {
                if (j >= square) {
                    Min[j] = min(Min[j], Min[j-square]+1);
                }
            }
            
            // When to break
            if (square > n)
                break;
        }
        return Min[n];
    }
};