/*
 * Problem: 762. Prime Number of Set Bits in Binary Representation
 * Approach: Hardware POPCNT + Bitmask Lookup
 * Time Complexity: O(N) - Loop runs exactly right-left times, doing O(1) hardware logic inside.
 * Space Complexity: O(1) - Pure integer registers, zero RAM allocation.
 */
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int prime_count = 0;
        
        // Step 1: The Magic Mask (Prime positions 2, 3, 5, 7, 11, 13, 17, 19 are 1s)
        // Binary: 0b10100010100010101100
        int prime_mask = 665772;
        
        // Step 2: Process the range
        for (int i = left; i <= right; i++) {
            
            // Trigger physical CPU circuit to count the bits instantly
            int bits = __builtin_popcount(i);
            
            // Shift our mask to the right by 'bits' spaces, and look at the first slot.
            // If it is a 1 (prime), we add 1. If it is a 0 (not prime), we add 0.
            prime_count += (prime_mask >> bits) & 1;
        }
        
        return prime_count;
    }
};