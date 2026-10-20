/*
 * Problem: 836. Rectangle Overlap
 * Approach: Mutual Exclusion (Shadow Projection)
 * Time Complexity: O(1) - 4 quick integer comparisons.
 * Space Complexity: O(1)
 */
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        // Define the edges for readability (you can visualize the coordinates easily)
        int R1_Left = rec1[0], R1_Bottom = rec1[1], R1_Right = rec1[2], R1_Top = rec1[3];
        int R2_Left = rec2[0], R2_Bottom = rec2[1], R2_Right = rec2[2], R2_Top = rec2[3];

        // Ask the 4 physical exclusion questions:
        bool is_Left  = R1_Right <= R2_Left;   // Is R1 entirely to the left of R2?
        bool is_Right = R1_Left  >= R2_Right;  // Is R1 entirely to the right of R2?
        bool is_Below = R1_Top   <= R2_Bottom; // Is R1 entirely below R2?
        bool is_Above = R1_Bottom >= R2_Top;   // Is R1 entirely above R2?

        // If ANY of those are true, they are separated.
        // We return the opposite (!), because we want to know if they OVERLAP.
        return !(is_Left || is_Right || is_Below || is_Above);
    }
};