class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        // Frequency map for the characters in t
        unordered_map<char, int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }
        
        // Variables to track the minimum window
        int left = 0, right = 0, minLength = INT_MAX, start = 0;
        int required = tFreq.size(); // Number of unique characters in t
        int formed = 0; // How many unique characters in t have been fully formed in the current window
        
        // Frequency map for the characters in the current window of s
        unordered_map<char, int> windowFreq;
        
        while (right < s.size()) {
            char c = s[right];
            windowFreq[c]++;
            
            // If the current character's frequency matches the desired frequency in t, it's "formed"
            if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                formed++;
            }
            
            // Try to shrink the window from the left as much as possible while maintaining the condition
            while (left <= right && formed == required) {
                c = s[left];
                
                // Update the result if the current window is smaller
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                
                // Shrink the window
                windowFreq[c]--;
                if (tFreq.count(c) && windowFreq[c] < tFreq[c]) {
                    formed--;
                }
                
                left++;
            }
            
            // Expand the window by moving the right pointer
            right++;
        }
        
        // If we found a valid window, return the substring; otherwise, return ""
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};
