class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int k = nums.size();
        vector<int> res(k,1);
        
        // Store the multiplications of all numbers to the left of ith number
        // excluding self.
        for (int i=1;i<k;i++){
            res[i]=res[i-1]*nums[i-1];
        }
        int temp = 1;
        // Go from right to left while collecting multiplications of all numbers to the right of ith
        // number
        for (int i=k-1;i>=0;i--){
            res[i]=res[i]*temp;
            temp*=nums[i];
        }
        return res;
    }
};