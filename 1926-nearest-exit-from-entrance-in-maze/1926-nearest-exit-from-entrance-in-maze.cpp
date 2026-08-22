class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        
        // Queue to store coordinates: {row, col}
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        
        // Mark the starting point as a wall so we don't go backwards
        maze[entrance[0]][entrance[1]] = '+';
        
        int steps = 0;
        
        // Up, Down, Left, Right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int current_level_size = q.size();
            
            // Check all positions at the current distance step
            for (int i = 0; i < current_level_size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                // Look in all 4 directions
                for (auto dir : directions) {
                    int next_row = r + dir.first;
                    int next_col = c + dir.second;
                    
                    // 1. Is it inside the maze?
                    // 2. Is it an empty space?
                    if (next_row >= 0 && next_row < rows && 
                        next_col >= 0 && next_col < cols && 
                        maze[next_row][next_col] == '.') {
                        
                        // Is it on the edge? (Exit found!)
                        if (next_row == 0 || next_row == rows - 1 || 
                            next_col == 0 || next_col == cols - 1) {
                            return steps + 1;
                        }
                        
                        // Mark as visited and add to queue
                        maze[next_row][next_col] = '+';
                        q.push({next_row, next_col});
                    }
                }
            }
            // Increase step count after checking one full wave of neighbors
            steps++;
        }
        
        // If we check everything and find nothing
        return -1;
    }
};