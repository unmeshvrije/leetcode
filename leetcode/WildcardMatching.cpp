class Solution {
public:

    void print_dp(vector<vector<bool>>& dp) {
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    bool isMatch(string s, string p) {
       int n1 = s.size(), n2 = p.size();
        vector<vector<bool>> res(n1 + 1, vector<bool>(n2 + 1));
        res[0][0] = true;
        for(int i=1; i<=n2; i++){
            if(p[i-1] == '*')
                res[0][i] = res[0][i-1];
        }
        
        //print_dp(res);
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                
                if (p[j-1] == '*') {
                    res[i][j] = res[i-1][j] || res[i][j-1];
                } else {
                    if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                        res[i][j] = res[i-1][j-1];
                    } else {
                        res[i][j] = false;
                    }
                }
                /*if(p[j-1] != '*'){
                    res[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && res[i-1][j-1]; 
                }
                else{
                    res[i][j] = res[i-1][j] || res[i][j-1];
                }*/
            }
        }
       // cout << "*******" << endl;
        
        //print_dp(res);
        return res[n1][n2];
        
    }
};