
class Solution {
public:

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      set<int> window;
      // window will contain 'k' elements at all times
        for(int i=0; i<(int)nums.size(); ++i){
            // Delete the smallest number from the set if we are surpassing the window
            if(i>k) window.erase(nums[i-1-k]);
            auto p = window.lower_bound(nums[i]-t);
            if(p!=window.end() && *p-nums[i]<=t) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};