/*
 * Problem: 1103. Distribute Candies to People
 * Approach: Circular Routing with Modulo
 * Time Complexity: O(sqrt(Candies)) - The amount given grows every step, 
 *                  so the stockpile depletes exponentially faster.
 * Space Complexity: O(N) - To store the array of people.
 */
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        // Step 1: Create our array of people, starting with 0 candies each.
        vector<int> result(num_people, 0);
        
        // Step 2: Our infinite step counter
        int i = 0; 
        
        while (candies > 0) {
            // Step 3: The 'min' check. 
            // We want to give (i + 1) candies. But if our stockpile is nearly empty, 
            // we can only give whatever candies are left.
            int give = min(candies, i + 1);
            
            // Step 4: The Modulo Router drops the candy into the correct bucket
            result[i % num_people] += give;
            
            // Step 5: Subtract what we just gave from the main stockpile
            candies -= give;
            
            // Move to the next step
            i++; 
        }
        
        return result;
    }
};