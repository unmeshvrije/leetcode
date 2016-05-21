class Solution {

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> result;
        int size = s.size();
        int nWords = words.size();
        
        if (nWords == 0) {
            return result;
        }
        
        int wordLength = words[0].length();
        
        unordered_map<string, int> table, orig_table;
        for (int i = 0; i < words.size(); ++i) {
            orig_table[words[i]]++;
        }
        
        for (int i = 0; i < size - (wordLength * nWords) +1; ++i) {
            table = orig_table;
            bool approve = true;
            
            for (int k = i; k < i + (wordLength * nWords); k+= wordLength) {
                string cur = s.substr(k, wordLength);
                if (table.find(cur) == table.end() || table[cur] == 0) {
                    approve = false;
                    break;
                } else {
                    table[cur]--;
                }
            }
            
            // All strings in the temp array were deleted
            // Means all of them were found
            if (approve) {
                result.push_back(i);
            }
            
        }
        
        return result;
    }
};