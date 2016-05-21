class Solution {
    
    private:
    void insertion_sort(vector<int>&nums)
    {
        for (int j = 1; j < nums.size(); ++j) {
            int key = nums[j];
            int i = j-1;
            while (i >= 0 && nums[i] > key) {
                nums[i+1] = nums[i];
                i--;
            }
            nums[i+1] = key;
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        vector<int> operands(4);
        int len = nums.size();
        
        insertion_sort(nums);
        //std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len -3; ++i) {
            //int target_for_3sum = target - nums[i];
            
            // This loop avoids duplicates
            // If we want same number at different positions appearing as the different answer item
            // then, we can remove this loop.
            while (i && nums[i] == nums[i-1]) {
              i++;
            }
            
            for (int j = i+1; j < len -2; ++j) {
                //int target_for_2sum = target_for_3sum - nums[j];
                while (j>i+1 && nums[j] == nums[j-1]) {
                  j++;
                }
                int l = j + 1;
                int r = len - 1;
                while (l < r) {
                    
                    if (nums[l]+nums[r]+nums[i] + nums[j] > target) {
                        r--;
                    } else if (nums[l]+nums[r]+nums[i] + nums[j] < target) {
                        l++;
                    } else {
                        
                        // Using push_back() method of vector results into "Memory limit exceeded message"
                        operands[0] = nums[i];
                        operands[1] = nums[j];
                        operands[2] = nums[l];
                        operands[3] = nums[r];
                        result.push_back(operands);
                        
                        // Following optimization is necessary for preventing "Time limit exceeded" message
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1]){
                            l++;
                        }
                        while (r > l && nums[r] == nums[r+1]) {
                            r--;
                        }
                    }
                }
                
            }
        }
        
        return result;
    }
};