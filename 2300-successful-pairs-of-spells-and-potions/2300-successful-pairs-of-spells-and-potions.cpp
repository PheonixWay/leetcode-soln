class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Step 1: Sort the potions array in ascending order
        sort(potions.begin(), potions.end());
        
        vector<int> result;
        int m = potions.size();
        
        // Step 2: Loop through each spell
        for (int i = 0; i < spells.size(); i++) {
            int left = 0;
            int right = m - 1;
            
            // This will store the position of the first potion that works.
            // We set it to 'm' initially, meaning "no potion works" by default.
            int first_valid_index = m; 
            
            // Binary Search
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                // We must use 'long long' here because multiplying two large integers 
                // can exceed the standard 32-bit integer limit and cause a crash.
                long long product = (long long)spells[i] * potions[mid];
                
                if (product >= success) {
                    // This potion is successful! 
                    // Record its index, but keep searching to the left to see if a weaker one also works.
                    first_valid_index = mid;
                    right = mid - 1;
                } else {
                    // This potion is too weak. We need to search to the right for stronger potions.
                    left = mid + 1;
                }
            }
            
            // Calculate how many potions worked and add to our result list
            int successful_count = m - first_valid_index;
            result.push_back(successful_count);
        }
        
        return result;
    }
};