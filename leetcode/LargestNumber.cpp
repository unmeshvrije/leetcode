/**
 * 
 * 3
 * 30
 * 34
 * 5
 * 9
 * 
 * all possible permutations of the array and check which is the largest
 * 
 * Helper function which accepts two stringized integers and tells which one is greater
*/

bool comp(string&a, string& b) {
    return a+b > b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numbers;
        string finalNumber = "";
        
        stringstream ss;
        for (int i = 0; i < nums.size(); ++i) {
            ss.str(string());
            ss << nums[i];
            numbers.push_back(ss.str());
        }
        
        sort(numbers.begin(), numbers.end(), comp);
        if (numbers[0][0] == '0') {
            return "0";
        }
        
        for (int i = 0; i < numbers.size(); ++i) {
            cout << numbers[i];
            finalNumber += numbers[i];
        }
        
        return finalNumber;
    }
};