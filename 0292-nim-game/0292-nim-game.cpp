/*
 * Problem: 292. Nim Game
 * Time Complexity: O(1) - Pure math, instant calculation.
 * Space Complexity: O(1) - No extra variables used.
 */
class Solution {
public:
    bool canWinNim(int n) {
        // If n is perfectly divisible by 4, you are doomed.
        // Otherwise, you win.
        return n % 4 != 0;
    }
};