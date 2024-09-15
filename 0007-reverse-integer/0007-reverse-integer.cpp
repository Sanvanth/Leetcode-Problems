#include <climits>

class Solution {
public:
    int reverse(int x) {
        int reversedNumber = 0;
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            // Check if the reverse would overflow before multiplying
            if (reversedNumber > INT_MAX / 10 || (reversedNumber == INT_MAX / 10 && digit > 7)) {
                return 0; // Overflow case for positive numbers
            }
            if (reversedNumber < INT_MIN / 10 || (reversedNumber == INT_MIN / 10 && digit < -8)) {
                return 0; // Overflow case for negative numbers
            }
            
            reversedNumber = reversedNumber * 10 + digit;
        }
        
        return reversedNumber;
    }
};
