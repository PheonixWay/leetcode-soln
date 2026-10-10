class Solution {
public:
    string convertToBase7(int num) {
        // Edge Case: Handle 0 immediately
        if (num == 0) return "0";
        
        // Step 1: Record if it is negative, then make it positive for clean math
        bool isNegative = num < 0;
        int n = abs(num);
        
        string result = "";
        
        // Step 2: Your exact core logic
        while (n > 0) {
            int remainder = n % 7;
            result += to_string(remainder);
            n /= 7;
        }
        
        // Step 3: If it was negative, attach the minus sign to the end
        if (isNegative) {
            result += "-";
        }
        
        // Step 4: Reverse the string directly in memory
        reverse(result.begin(), result.end());
        
        return result;
    }
};