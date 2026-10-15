/*
 * Problem: 728. Self Dividing Numbers
 * Approach: Pure Integer Base-10 Extraction
 * Time Complexity: O(N * D) - Where N is the range and D is the number of digits (max 4).
 * Space Complexity: O(1) - No strings or extra memory used.
 */
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        
        // Step 1: Scan every number in the range
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                result.push_back(i);
            }
        }
        
        return result;
    }

private:
    // Helper Function: The Base-10 Simulator
    bool isSelfDividing(int num) {
        int temp = num; // Create a working copy so we don't destroy the original number
        
        while (temp > 0) {
            // Extract the right-most digit
            int digit = temp % 10;
            
            // The Filter: 
            // 1. Check if it's 0 to prevent a hardware crash.
            // 2. Check if the original number is perfectly divisible by the digit.
            if (digit == 0 || num % digit != 0) {
                return false; 
            }
            
            // Shift the number right by 1 decimal place
            temp /= 10;
        }
        
        // If it survives the entire loop without returning false, it is perfect!
        return true;
    }
};