class NumArray {
    private:
    int *sums;
public:

//   3 4 2 7
//   0 1 2 3 
//   3 7 9 16 25
//
    NumArray(vector<int> &nums) {
        sums = new int[nums.size()];
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            k += nums[i];
            sums[i] = k;
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sums[j];
        }
        
        if (j == 0) {
            return sums[0];
        }
        return sums[j] - sums[i-1];
    }
    
    ~NumArray(){
        delete sums;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);