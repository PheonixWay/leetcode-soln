/*
 * Problem: 628. Maximum Product of Three Numbers
 * Approach: Single Pass Extremes Tracking
 * Time Complexity: O(N) - We only read the array exactly once.
 * Space Complexity: O(1) - 5 variables of memory used.
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Step 1: Initialize the 5 extremes
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN; // Top 3
        int min1 = INT_MAX, min2 = INT_MAX;                 // Bottom 2
        
        // Step 2: The Assembly Line Filter
        for (int n : nums) {
            // Filter for the 3 Largest Numbers
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }
            
            // Filter for the 2 Smallest (most negative) Numbers
            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }
        
        // Step 3: Compare Scenario A vs Scenario B
        // (Constraints note: Max value is 1000^3 = 1 Billion, which safely fits in a 32-bit int)
        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};