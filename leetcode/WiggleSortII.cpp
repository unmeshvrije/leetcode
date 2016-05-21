class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        
        int n = temp.size();
        int i = -1;
        int j = n-1;
        if (n%2 == 0) {
            i = (n/2) - 1;
        } else {
            i = n/2;
        }
        
        int index = 0;
        int mid = i;
        while (j != mid) {
            nums[index++] = temp[i];
            nums[index++] = temp[j];
            j--;
            i--;
        }
        
        if (i >= 0) {
            nums[index++] = temp[i];
        }
    }
};