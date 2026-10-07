/*
 * Problem: 415. Add Strings
 * Approach: Column Addition + ASCII Translation
 * Time Complexity: O(max(N, M)) - Where N and M are the lengths of the strings.
 * Space Complexity: O(max(N, M)) - To store the result string.
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        // Start our pointers at the very end (right side) of both strings
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        
        int carry = 0;
        string result = "";
        
        // Keep looping if there are digits left in either string, OR if we have a carry
        while (i >= 0 || j >= 0 || carry > 0) {
            
            // Extract the digits. If one string is shorter and runs out, just use 0.
            int digit1 = 0;
            if (i >= 0) {
                digit1 = num1[i] - '0'; // ASCII translation trick
                i--;
            }
            
            int digit2 = 0;
            if (j >= 0) {
                digit2 = num2[j] - '0'; // ASCII translation trick
                j--;
            }
            
            // Add the column
            int sum = digit1 + digit2 + carry;
            
            // Find the new carry for the next loop (e.g., 15 / 10 = 1)
            carry = sum / 10;
            
            // Find the single digit to keep (e.g., 15 % 10 = 5)
            int digit_to_keep = sum % 10;
            
            // Turn it back into a character and attach it to the END of our result
            result += to_string(digit_to_keep);
        }
        
        // Because we added right-to-left and attached to the end, the string is backwards.
        // We flip it to get the final correct answer!
        reverse(result.begin(), result.end());
        
        return result;
    }
};