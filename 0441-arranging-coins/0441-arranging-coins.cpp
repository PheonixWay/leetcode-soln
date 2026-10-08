/*
 * Problem: 441. Arranging Coins
 * Approach: Pure Math (Quadratic Equation)
 * Time Complexity: O(1) - The CPU solves this instantly in a single hardware cycle.
 * Space Complexity: O(1)
 */
class Solution {
public:
    int arrangeCoins(int n) {
        // Step 1: 
        // Cast the 32-bit int to a 64-bit long long so it can handle 16 Billion.
        long long N = n;
        
        // Step 2: math formula
        long long k = (sqrt(8 * N + 1) - 1) / 2;
        
        // Step 3: Cast it back to a standard 32-bit int for the final answer
        return (int)k;
    }
};