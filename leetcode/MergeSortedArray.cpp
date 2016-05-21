class Solution {
public:

    void move_to_end(vector<int>&v, int extra) {
        int n = v.size();
        
        cout << "n = " << n << endl;
        cout << "extra = " << extra << endl;
        
        for (int i = n-1, j = (n-extra)-1; j >=0; --i, --j) {
            cout << "v [" << i << "]  = v [" << j << "] " << endl;
            v[i] = v[j];
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        move_to_end(nums1, n);
        
        if (nums1.size() == n) {
            //nums1 has no elements of its own, Copy the nums1 and be done
            for (int g = 0; g < nums1.size(); ++g) {
                nums1[g] = nums2[g];
            }
            return;
        }
        
        int i = n;
        int j = 0;
        int k = 0;
        while (j < n) {
            
            if (nums2[j] < nums1[i]) {
                nums1[k++] = nums2[j++];
            } else {
                nums1[k++] = nums1[i++];
            }
            if (i >= (m+n)) {
                break;
            }
        }
        
        while(j < n) {
            nums1[k++] = nums2[j++];
        }
    }
};