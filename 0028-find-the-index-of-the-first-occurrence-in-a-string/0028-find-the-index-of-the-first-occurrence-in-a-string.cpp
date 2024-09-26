class Solution {
public:
    int strStr(string haystack, string needle) {
        // Edge case: If needle is an empty string, return 0
        if (needle.empty()) {
            return 0;
        }
        
        int haystackLen = haystack.size();
        int needleLen = needle.size();
        
        // Iterate through haystack with a window of needle's length
        for (int i = 0; i <= haystackLen - needleLen; i++) {
            // If substring from current index matches needle, return the index
            if (haystack.substr(i, needleLen) == needle) {
                return i;
            }
        }
        
        // If no match is found, return -1
        return -1;
    }
};
