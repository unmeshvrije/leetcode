class Solution {
    
    private:
    
    // Maintain index at which character is matched in the guess
    std::map<int, bool> matched;
    
    // Maintain counts of character in secret and guess strings
    std::map<char, pair<int,int>> counts;
    
public:
    string getHint(string secret, string guess) {
        
        if (secret.size() != guess.size()) {
            return "";
        }
    
        int bulls = 0;
        for (int i = 0; i < guess.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
                matched[i] = true;
            } else {
                matched[i] = false;
                counts[secret[i]].first++;
                counts[guess[i]].second++;
            }
        }
        
        int cows = 0;
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i].first && counts[i].second) {
                cows += std::min(counts[i].first, counts[i].second);
            }
        }
        
        stringstream ss;
        ss << bulls <<"A" << cows << "B";
        return ss.str();
    }
};