class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorResult = start ^ goal;
        
        // Count the number of 1s in the XOR result (Hamming weight)
        int count = 0;
        while (xorResult > 0) {
            count += xorResult & 1;  // Add 1 if the last bit is 1
            xorResult >>= 1;         // Right shift to check the next bit
        }
        
        return count;
    }
};
