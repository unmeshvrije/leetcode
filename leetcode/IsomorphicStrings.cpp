class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m != n) {
            return false;
        }
        
        unordered_map<char, pair<char, int>> doubleHash;
        unordered_map<char, pair<char,int>> reverse;
        for (int i = 0; i < n; ++i) {
            pair<char,int> revCharCount = reverse[t[i]];
            if (revCharCount.second == 1 && s[i] != revCharCount.first) {
                return false;
            }
            
            pair<char,int> charCount = doubleHash[s[i]];
            if (charCount.second > 0 && charCount.first != t[i]) {
                return false;
            }
            reverse[t[i]] = make_pair(s[i], 1);
            doubleHash[s[i]] = make_pair(t[i], charCount.second+1);
        }
        
        return true;
    }
};