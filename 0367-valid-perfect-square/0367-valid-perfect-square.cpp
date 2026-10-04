/*
 * Approach 1: Math (Sum of Odd Numbers)
 * Time Complexity: O(sqrt(n)) 
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        int odd_number = 1;
        while (num > 0) {
            num = num - odd_number;
            odd_number = odd_number + 2; // Move to the next odd number
        }
        return num == 0;
    }
};