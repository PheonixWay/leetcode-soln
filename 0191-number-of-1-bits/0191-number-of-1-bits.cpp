/*
 * Problem: 191. Number of 1 Bits
 * Time Complexity: O(k) - Where 'k' is the number of '1' bits. It skips all the zeros!
 * Space Complexity: O(1)
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        // Keep shooting down the '1' bits until none are left
        while (n > 0) {
            n = n & (n - 1); // Delete the rightmost '1' bit
            count++;         // Add 1 to our total count
        }
        
        return count;
    }
};