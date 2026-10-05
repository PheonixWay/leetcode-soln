/*
 * Problem: 405. Convert a Number to Hexadecimal
 * Approach: Mathematics (Division and Modulo)
 */
class Solution {
public:
    string toHex(int num) {
        // Base case
        if (num == 0) return "0";
        
        string hexChars = "0123456789abcdef";
        string result = "";
        
        // This single line fixes the negative number trap!
        unsigned int n = num; 
        
        while (n > 0) {
            // Get the remainder using standard Math
            int remainder = n % 16; 
            
            // Map the remainder to our dictionary
            result = hexChars[remainder] + result; 
            
            // Divide by 16 to shrink the number for the next loop
            n = n / 16; 
        }
        
        return result;
    }
};