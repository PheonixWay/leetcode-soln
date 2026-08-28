/*
 * Problem: 2462. Total Cost to Hire K Workers
 * Logic: Two Min-Heaps acting as two visibility windows.
 */
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
      
        priority_queue<int, vector<int>, greater<int>> frontWindow;
        priority_queue<int, vector<int>, greater<int>> backWindow;
        
        long long total_cost = 0;
        
      
        int left = 0;
        int right = costs.size() - 1;
        
        
        while (k > 0) {
            
            
            while (frontWindow.size() < candidates && left <= right) {
                frontWindow.push(costs[left]);
                left++;
            }
            
            while (backWindow.size() < candidates && left <= right) {
                backWindow.push(costs[right]);
                right--;
            }
            
        
            int front_best = frontWindow.size() > 0 ? frontWindow.top() : INT_MAX;
            int back_best = backWindow.size() > 0 ? backWindow.top() : INT_MAX;
            
            
            if (front_best <= back_best) {
                total_cost += front_best;
                frontWindow.pop();
            } else {
                total_cost += back_best;
                backWindow.pop();  
            }
            
            k--; 
        }
        
        return total_cost;
    }
};