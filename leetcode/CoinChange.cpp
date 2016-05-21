class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        std::sort(coins.begin(), coins.end());
        
        vector<int> numCoins(amount+1);
        numCoins[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            numCoins[i] = INT_MAX;
        }
        
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i]) {
                    if (numCoins[j-coins[i]] != INT_MAX) {
                        numCoins[j] = min(numCoins[j], numCoins[j-coins[i]] + 1);
                    }
                }
            }
        }
        
        int ret = numCoins[amount];
        if (ret == INT_MAX) {
            ret = -1;
        }
        
        return ret;
    }
};