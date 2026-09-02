/*
 * Problem: 162. Find Peak Element
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // We use left < right instead of left <= right
        // because we are comparing mid with mid + 1. 
        // If left == right, mid + 1 would go out of bounds.
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Look at the slope
            if (nums[mid] < nums[mid + 1]) {
                // We are walking UP. The peak is to the right.
                left = mid + 1;
            } else {
                // We are walking DOWN. The peak is at mid or to the left.
                // We do not do mid - 1 because mid itself might be the peak.
                right = mid;
            }
        }
        
        // When the loop ends, left and right will point to the exact same index.
        // That index is our peak element.
        return left;
    }
};