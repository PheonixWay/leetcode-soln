/*
 * Problem: 405. Convert a Number to Hexadecimal
 * Time Complexity: O(1) - Max 8 loops for a 32-bit number.
 * Space Complexity: O(1)
 */
class Solution {
public:
    string toHex(int num) {
        // Base case: If the number is 0, just return "0"
        if (num == 0) return "0";
        
        // This array maps our 4-bit numbers (0-15) to their hex characters
        string hexChars = "0123456789abcdef";
        string result = "";
        
        // Convert to unsigned int to perfectly handle negative two's complement
        unsigned int n = num; 
        
        while (n > 0) {
            // Step 1: Extract the last 4 bits using the & 15 mask
            int last_four_bits = n & 15; 
            
            // Step 2: Map it to a character and add it to our result
            result = hexChars[last_four_bits] + result; 
            
            // Step 3: Shift the binary number to the right by 4 spaces
            n = n >> 4; 
        }
        
        return result;
    }
};