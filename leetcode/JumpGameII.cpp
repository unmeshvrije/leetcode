class Solution {
public:
    int minimum_of_reachable(int start, int end, int* hops, int n) {
        int minimum = INT_MAX;
        
        if (end > n) {
            end = n;
        }
        
        if (end < start) {
            return n;
        }
        
        int i = end;
        
        while (i >= start) {
            
            if (hops[i] == 1) {
                return 1;
            }
            
            if (hops[i] < minimum) {
                minimum = hops[i];
            }
            i--;
        }
        return minimum;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1){
            return 0;
        }
        
        int *hops = new int[n];
        hops[n-1] = 0;
        hops[n-2] = 1; // Always reachable in 1 hop
        
        for (int i = n-3, distance = 2; i >=0; --i, distance++) {
            if (nums[i] >= distance) {
                hops[i] = 1;
            } else {
                hops[i] = minimum_of_reachable(i+1, i+nums[i], hops, n) + 1;
            }
        }
        
        return hops[0];
    }
};