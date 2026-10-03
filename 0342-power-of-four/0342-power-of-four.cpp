/*
 * Problem: 342. Power of Four
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        // Step 1: Ensure it's a positive Power of 2 (destroys all non-powers of 2)
        bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);
        
        // Step 2: Ensure the single '1' bit is NOT in an odd position
        // 0xAAAAAAAA in binary is 10101010101010101010101010101010
        bool isEvenPosition = (n & 0xAAAAAAAA) == 0;
        
        return isPowerOfTwo && isEvenPosition;
    }
};