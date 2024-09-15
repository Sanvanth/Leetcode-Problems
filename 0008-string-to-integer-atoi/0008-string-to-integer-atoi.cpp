#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, sign = 1;
        long result = 0;
        
        // Step 1: Ignore leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for sign character
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Handle out of range cases
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
            
            i++;
        }

        return result * sign;
    }
};
