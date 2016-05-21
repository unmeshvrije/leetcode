class Solution {
    private:
    
    unsigned long long nChooseK(unsigned long long n, unsigned long long k) {
        if (k == 0) {
            return 1;
        }
        
        return (n * nChooseK(n-1, k-1))/k;
    }
    
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if (rowIndex == 0) {
            result.push_back(1);
            return result;
        }
        
        int k = 0;
        for (int i = 0; i <= rowIndex/2; ++i, ++k) {
            unsigned long long ans = nChooseK(rowIndex, k);
            //cout << ans << endl;
            result.push_back(ans);
        }
        
        vector<int> coeff(result);
        std::reverse(coeff.begin(), coeff.end());
        
        if (rowIndex%2 == 0) {
            result.insert(result.end(), coeff.begin()+1, coeff.end());
        } else {
            result.insert(result.end(), coeff.begin(), coeff.end());
        }
        return result;
    }
};