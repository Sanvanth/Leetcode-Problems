class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPartition;
        backtrack(s, 0, currentPartition, result);
        return result;
    }
    
private:
    void backtrack(const string& s, int start, vector<string>& currentPartition, vector<vector<string>>& result) {
        // Base case: if we have reached the end of the string
        if (start == s.size()) {
            result.push_back(currentPartition);
            return;
        }
        
        // Try to partition the string starting at index `start`
        for (int end = start; end < s.size(); end++) {
            // If the substring from start to end is a palindrome, proceed
            if (isPalindrome(s, start, end)) {
                // Include the palindrome substring in the current partition
                currentPartition.push_back(s.substr(start, end - start + 1));
                
                // Recurse to partition the rest of the string
                backtrack(s, end + 1, currentPartition, result);
                
                // Backtrack by removing the last added substring
                currentPartition.pop_back();
            }
        }
    }
    
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
