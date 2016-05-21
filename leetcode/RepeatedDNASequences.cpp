class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> str;
        vector<string> result;
        if (s.size() < 10) {
            return result;
        }
        
        for (int i = 0; i <= s.size()-10; ++i) {
            string part = s.substr(i,10);
            if (str[part] == 1) {
                result.push_back(part);
            }
            str[part]++;
            
        }
        
        return result;
    }
};