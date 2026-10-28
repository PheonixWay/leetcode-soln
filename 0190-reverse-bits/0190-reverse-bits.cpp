/*
 * Approach: 32-Bit Assembly Line
 * Time Complexity: O(1) - Loop runs exactly 32 times, regardless of the number.
 * Space Complexity: O(1) - Entirely inside CPU registers.
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        // A 32-bit integer always has exactly 32 bits to process
        for (int i = 0; i < 32; i++) {
            
            // Step 1: Make room on the conveyor belt by shifting result left
            result <<= 1;
            
            // Step 2: Extract the right-most bit from 'n' and glue it onto 'result'
            result |= (n & 1);
            
            // Step 3: Shift 'n' right to load the next bit into the extraction slot
            n >>= 1;
        }
        
        return result;
    }
};