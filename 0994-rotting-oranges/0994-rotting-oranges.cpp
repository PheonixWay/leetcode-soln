/*
 * Problem: 994. Rotting Oranges
 * 
 * Intuition: 
 * We use Multi-Source BFS because the rot spreads simultaneously from all 
 * initially rotten oranges, level by level (minute by minute).
 * 
 * Complexity:
 * - Time: $O(M \times N)$ where M is rows and N is cols. We visit each cell at most once.
 * - Space: $O(M \times N)$ for the queue in the worst case (if all oranges are rotten).
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Queue to store coordinates of rotten oranges: {row, col}
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        // Step 1: Initialize the Queue and count fresh oranges
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c}); // Drop all initial zombies into the queue
                } else if (grid[r][c] == 1) {
                    freshCount++;   // Count humans
                }
            }
        }
        
        // If there are no fresh oranges to begin with, time taken is 0
        if (freshCount == 0) return 0;
        
        int minutes = 0;
        
        // Direction array for moving: Up, Down, Left, Right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Step 2: BFS - The Ripple Effect
        while (!q.empty()) {
            int size = q.size(); // How many zombies are acting in THIS minute
            bool rottedSomeone = false;
            
            // Process all zombies for the current minute
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                int r = curr.first;
                int c = curr.second;
                q.pop();
                
                // Check all 4 neighbors
                for (auto d : dirs) {
                    int nr = r + d.first;  // new row
                    int nc = c + d.second; // new col
                    
                    // Boundary check AND check if it's a fresh orange
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;      // Make it rotten
                        freshCount--;          // One less fresh orange
                        q.push({nr, nc});      // Add new zombie to queue for the next minute
                        rottedSomeone = true;  // Mark that we did some work this minute
                    }
                }
            }
            
            // Only increment time if we actually rotted at least one orange this minute
            if (rottedSomeone) {
                minutes++;
            }
        }
        
        // Step 3: Did any fresh orange survive?
        if (freshCount > 0) {
            return -1; // Someone is trapped behind walls
        }
        
        return minutes;
    }
};