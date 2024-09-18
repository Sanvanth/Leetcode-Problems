class Solution {
public:
    bool isPalindrome(int x) {
        // Handle negative numbers directly
        if (x < 0) {
            return false;
        }

        // Extract digits one by one and compare them in reverse order
        long long reversed = 0;
        int original = x;
        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        // Check if the reversed number is equal to the original
        return reversed == original;
    }
};