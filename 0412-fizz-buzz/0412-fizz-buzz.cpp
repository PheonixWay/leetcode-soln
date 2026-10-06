/*
 * Problem: 412. Fizz Buzz
 * Approach: Mathematics (Modulo & Lowest Common Multiple)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        
        for (int i = 1; i <= n; i++) {
            // Check the Lowest Common Multiple (15) FIRST!
            if (i % 15 == 0) {
                result.push_back("FizzBuzz");
            } 
            // Then check the individual prime numbers
            else if (i % 3 == 0) {
                result.push_back("Fizz");
            } 
            else if (i % 5 == 0) {
                result.push_back("Buzz");
            } 
            // If math fails, just print the number
            else {
                result.push_back(to_string(i));
            }
        }
        
        return result;
    }
};