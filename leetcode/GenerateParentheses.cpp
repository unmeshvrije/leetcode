class Solution {
public:
    void parenthesisUtil(vector<string>& result, string brackets, int n, int cntOpening, int cntClosing) {
        if (cntOpening == cntClosing && cntOpening == n) {
            result.push_back(brackets);
            return;
        }
        
        if (cntOpening < n) {
            parenthesisUtil(result, brackets+"(", n, cntOpening+1, cntClosing);
        }
        if (cntClosing < n && cntOpening > cntClosing) {
            parenthesisUtil(result, brackets+")", n, cntOpening, cntClosing+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        parenthesisUtil(result, "(", n, 1, 0);
        return result;
    }
};