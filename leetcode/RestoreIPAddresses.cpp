class Solution {
    
    bool isValidIp(string s, int i, int j) {
        if (i > j || i >= s.size() || j >= s.size()) {
            return false;
        }
        
        int ip;
        string sub = s.substr(i, (j-i)+1);
        
        // discard substrings like "00", "01" "010"
        if (sub.size() > 1 && sub[0] == '0') {
            return false;
        } 
        
        stringstream ss(sub);
        ss >> ip;
        
        return (ip >= 0 && ip <= 255);
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        
        int size = s.size();
        if (size > 12) {
            return result;
        }
        
        for (int i = 0, j = 2; j >= i; j--) {
            string ip1 ="";
            if (isValidIp(s, i, j)) {
                ip1 += s.substr(i, (j-i)+1);

                for (int k = j+1, l = k+2; l >= k; --l) {
                    string ip2 = ip1;
                    if (isValidIp(s, k, l)) {
                        ip2 += ".";
                        ip2 += s.substr(k, (l-k)+1);

                        for(int m = l+1, n = m+2; n >=m; --n) {
                            string ip3 = ip2;
                            if (isValidIp(s, m, n)) {
                                ip3 += ".";
                                ip3 += s.substr(m, (n-m)+1);
                                
                                for (int p = n+1, q = p+2; q>=p; --q) {
                                    string ip4 = ip3;
                                    if (isValidIp(s, p, q)) {
                                        ip4 += ".";
                                        ip4 += s.substr(p, (q-p)+1);
                                        // If q is the last digit/character in the string,
                                        // Then add this string to the result
                                        if (q+1 == size) {
                                            result.push_back(ip4);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};