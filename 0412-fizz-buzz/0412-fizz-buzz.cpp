/*
 * Problem: 412. Fizz Buzz
 * Approach: String Builder + Addition Counters (Zero Division)
 * Time Complexity: O(n) - Lightning fast CPU addition.
 * Space Complexity: O(n) - To store the result array.
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        

        int count3 = 0;
        int count5 = 0;
        
        for (int i = 1; i <= n; i++) {
            count3++;
            count5++;
            string current_string = "";
            
            // Filter 1
            if (count3 == 3) {
                current_string += "Fizz";
                count3 = 0; // Reset the counter
            }
            
            // Filter 2
            if (count5 == 5) {
                current_string += "Buzz";
                count5 = 0; // Reset the counter
            }
            
        
            if (current_string.empty()) {
                current_string = to_string(i);
            }
            
            // Save the final result
            result.push_back(current_string);
        }
        
        return result;
    }
};