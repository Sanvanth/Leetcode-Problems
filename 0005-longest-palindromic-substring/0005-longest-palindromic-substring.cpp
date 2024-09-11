class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 1;

        for (int i = 0; i < s.size(); ++i) {
            // Check for odd length palindromes (single center)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes (two centers)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Get the maximum length palindrome for the current center
            int len = max(len1, len2);

            // Update the starting index and maxLength if we find a longer palindrome
            if (len > maxLength) {
                start = i - (len - 1) / 2;
                maxLength = len;
            }
        }
        return s.substr(start, maxLength);
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        // Expand outwards as long as the characters are equal and within bounds
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
};
