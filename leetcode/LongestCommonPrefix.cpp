class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return "";
        }
        
        if (n == 1) {
            return strs[0];
        }
        
        string answer = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            for (int j = 0; j < answer.size(); ++j) {
                if (strs[i][j] != answer[j]) {
                    answer = answer.substr(0,j);
                    break;
                }
            }
        }
        
        return answer;
    }
};