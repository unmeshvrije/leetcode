class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {
            return false;
        }
        
        map<char,int> dict;
        for (int i = 0; i < s.size(); ++i) {
            dict[s[i]]++;
        }
        
        for (int i = 0; i < t.size(); ++i) {
            dict[t[i]]--;
        }
        
        for (map<char,int>::iterator it = dict.begin(); it != dict.end(); ++it) {
            if (it->second > 0) {
                return false;
            }
        }
        
        return true;
    }
};