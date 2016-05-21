/**
 * Count array , visited array and modifying the string in place as we progress
*/
class Solution {
    private:
    std::map<char, int> count;
    std::map<char, bool> visited;
public:

    string removeDuplicateLetters(string s) {
        
        string result(26,'0');
        int size = 0;
        // Store all counts for every character.
        for (int i = 0; i < s.size(); ++i) {
            count[s[i]]++;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            count[s[i]]--;
            
            if (visited[s[i]]) {
                continue;
            }
            
            int j = size-1;
            for (; j > -1; --j) {
                
                // If lexicographically bigger character with positive count, found in the preceding string
                // then set its visited as false because we are going to visit that again.
                if (result[j] > s[i] && count[result[j]]) {
                    visited[result[j]] = false;
                } else {
                    break;
                }
            }
            size = j+1;
            result[size++] = s[i];
            visited[s[i]] = true;
        
        }
        
       // result[size] = '\0';
        
        
        return result.substr(0,size);
    }
};