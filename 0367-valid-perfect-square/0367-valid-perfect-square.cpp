/*
 * Approach 2: Binary Search
 * Time Complexity: O(log n) - Lightning fast.
 * Space Complexity: O(1)
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        // Base case
        if (num == 1) return true;
        
        long left = 1;
        long right = num;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid; // Uses 'long' to survive integer overflow
            
            if (square == num) {
                return true; // We found the exact root
            } else if (square < num) {
                left = mid + 1; // Guess was too low, search higher
            } else {
                right = mid - 1; // Guess was too high, search lower
            }
        }
        
        return false; // If we narrow it down to nothing, it's not a perfect square
    }
};