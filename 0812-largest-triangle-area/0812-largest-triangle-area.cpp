/*
 * Problem: 812. Largest Triangle Area
 * Approach: Shoelace Formula (Coordinate Geometry)
 * Time Complexity: O(N^3) - 19,600 operations max, instant for a CPU.
 * Space Complexity: O(1) - Pure math, no extra arrays or memory used.
 */
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0.0;
        int n = points.size();
        
        // Check every possible combination of 3 points
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    
                    // The Shoelace Formula:
                    // points[i][0] is x1, points[i][1] is y1
                    double area = 0.5 * abs(
                        points[i][0] * (points[j][1] - points[k][1]) +
                        points[j][0] * (points[k][1] - points[i][1]) +
                        points[k][0] * (points[i][1] - points[j][1])
                    );
                    
                    // Keep the largest area found
                    max_area = max(max_area, area);
                }
            }
        }
        
        return max_area;
    }
};