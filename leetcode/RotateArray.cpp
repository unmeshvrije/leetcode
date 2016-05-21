class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void printVec(vector<int>& vec) {
        cout << "[ ";
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i+1 < vec.size()) {
                cout << ",";
            }
        }
        cout << " ]" << endl;
    }
    void rotateUtil(vector<int>& nums, int start, int end) {
        if (start > end || start < 0 || end >= nums.size()) {
            return;
        }
        
        for (int i = start, j = end; i<j ; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) {
            k = k %n;
        }
        rotateUtil(nums, 0, n-1);
        //printVec(nums);
        rotateUtil(nums, 0, k-1);
        //printVec(nums);
        rotateUtil(nums, k, n-1);
        //printVec(nums);
    }
};