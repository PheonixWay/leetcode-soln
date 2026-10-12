class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // Step 1: Base case (No operations)
        // If there are no operations, the matrix remains all 0s. 
        // 0 is the max value, and EVERY cell holds it, so return the total area.
        if (ops.empty()) {
            return m * n;
        }

        // Step 2: Set our boundaries to the absolute maximum desk size
        int min_row = m;
        int min_col = n;
        
        // Step 3: Find the smallest sheet of paper (The Intersection)
        for (const auto& op : ops) {
            min_row = min(min_row, op[0]);
            min_col = min(min_col, op[1]);
        }
        
        // Step 4: Calculate the total area of the overlap
        return min_row * min_col;



    }
};