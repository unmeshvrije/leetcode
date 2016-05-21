class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) {
            return 0;
        }
        
        if (n == 1) {
            return 1;
        }
        
        int r = 1;
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1]+1;
            }
        }
        
        for (int i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                if (candies[i] <= candies[i+1]) {
                    candies[i] = candies[i+1]+1;
                }
            }
        }
        
        int totalCandies = 0;
        for (int i = 0; i < n; ++i) {
            totalCandies += candies[i];
        }
        
        return totalCandies;
    }
};