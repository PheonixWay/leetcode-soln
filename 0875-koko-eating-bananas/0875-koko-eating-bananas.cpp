class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        
        // Maximum speed to right variable
        for (int p : piles) {
            right = max(right, p);
        }

        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2; // mid is our current test speed 'k'
            
            // Calculate total hours needed at speed 'mid'
            long long total_hours = 0; 
            for (int p : piles) {
                total_hours += p / mid;
                if (p % mid != 0) { 
                    total_hours++;
                }
            }
            
            // Step 3: Shift boundaries based on total_hours
            if (total_hours <= h) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};