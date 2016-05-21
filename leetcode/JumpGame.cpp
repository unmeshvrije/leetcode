/**
 * The idea is simple:
 * [3, 2, 1, 0, 4]
 * Second last element must at least be 1 to reach the last element, If it is not, then
 * thrid last must be at least 2 and so on. When the criterion is satisfied, 
 * previous element may just reach the element that can already reach the last element
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            true;
        }
        
        int distance = 1;
        for (int i = n-2; i >= 0; --i) {
            if (nums[i] < distance) {
                distance += 1;
            } else {
                // We can reach the last index from here
                // Previous element may just reach me
                distance = 1;
            }
        }
        
        return (distance == 1);
    }
};