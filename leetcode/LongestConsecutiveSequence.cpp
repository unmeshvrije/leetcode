/**
 * Scan the array. Find minimum and maximum element.
 * 1
 * 200
*/

class Solution {
    
    private:
    void print_queue(priority_queue<int, vector<int>, std::greater<int>> q) {
        while (!q.empty()) {
            cout << q.top() << " ";
            q.pop();
        }
        cout << endl;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int, vector<int>, std::greater<int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
        }
        
        print_queue(q);
        
        int maxCount = 1;
        int cnt = 1;
        int cur = q.top(); q.pop();
        while (!q.empty()) {
            int prev = cur;
            cur  = q.top(); q.pop();
            if (prev == cur) {
                continue;
            }
            if (prev+1 == cur) {
                cnt++;
            } else {
                if (cnt > maxCount) {
                    maxCount = cnt;
                }
                cnt = 1;
            }
        }
        
        if (cnt > maxCount){
            maxCount = cnt;
        }
        
        return maxCount;
    }
};