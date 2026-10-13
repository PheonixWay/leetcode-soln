class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Let the built-in sorting engine organize the numbers
        sort(nums.begin(), nums.end());
        
        // Step 2: Calculate both mathematical scenarios using exact indexes
        int scenarioA = nums[n-1] * nums[n-2] * nums[n-3];
        int scenarioB = nums[0] * nums[1] * nums[n-1];
        
        // Step 3: Return the winner
        return max(scenarioA, scenarioB);
    }
};