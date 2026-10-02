/*
 * Problem: 326. Power of Three
 * Time Complexity: O(1) - Pure math, instant calculation.
 * Space Complexity: O(1) - No extra variables used.
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base case: Powers of 3 must be strictly positive
        if (n <= 0) {
            return false;
        }
        
        // 1162261467 is 3^19, the largest power of 3 that fits in a 32-bit integer.
        // If n is a true power of 3, it will divide into this perfectly.
        return 1162261467 % n == 0;
    }
};