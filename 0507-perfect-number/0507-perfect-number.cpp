/*
 * Problem: 507. Perfect Number
 * Approach: Square Root Limit (Factor Pairs)
 * Time Complexity: O(sqrt(N)) - Drops 100,000,000 operations down to 10,000.
 * Space Complexity: O(1)
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // Step 1: Base Case
        if (num <= 1) return false;
        
        // We always start our sum with 1, since 1 is a divisor for every number.
        int sum = 1;
        
        // Step 2: Search only up to the Square Root Mirror Point
        // Writing 'i * i <= num' is a hardware trick! 
        // It avoids using the slow decimal math of sqrt() and keeps the CPU entirely in fast integer memory.
        for (int i = 2; i * i <= num; i++) {
            
            if (num % i == 0) {
                // Add the left factor
                sum += i;
                
                // Add the right factor (the mirror)
                // We use an 'if' statement to prevent double-counting perfect squares (like 6x6=36)
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }
        
        // Step 3: Check if the sum perfectly matches the original number
        return sum == num;
    }
};