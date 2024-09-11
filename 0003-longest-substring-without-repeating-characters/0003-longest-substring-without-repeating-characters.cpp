class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(128, -1); // Array to store the last seen index of each character (initialized to -1)
        int maxLength = 0;
        int start = 0; // Start of the current window

        for (int end = 0; end < s.size(); end++) {
            // If the character is seen before, move start to the right of the last occurrence
            if (charIndex[s[end]] != -1) {
                start = max(start, charIndex[s[end]] + 1);
            }

            // Update the last seen index of the character
            charIndex[s[end]] = end;
            
            // Update the maximum length
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
