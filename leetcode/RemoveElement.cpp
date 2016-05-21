class Solution {
    private:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == val) {
                cnt++;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == val) {
                for (int j = i+1; j < n; ++j) {
                    if (nums[j] != val) {
                        swap(nums[i], nums[j]);
                    }
                }
            }
        }
        
        return n-cnt;
    }
};