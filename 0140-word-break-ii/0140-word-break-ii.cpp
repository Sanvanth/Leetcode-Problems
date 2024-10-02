class Solution {
public:
    // Helper function to perform backtracking and memoization
    vector<string> wordBreakHelper(string s, unordered_set<string>& wordDict, unordered_map<string, vector<string>>& memo) {
        // If the result for the current substring is already computed, return it
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        vector<string> result;
        
        // If the string is empty, return a list containing an empty sentence
        if (s.empty()) {
            result.push_back("");
            return result;
        }

        // Iterate through each prefix of the string
        for (int i = 1; i <= s.length(); i++) {
            string prefix = s.substr(0, i);
            // If the prefix exists in the dictionary
            if (wordDict.find(prefix) != wordDict.end()) {
                // Recursively call on the remaining suffix
                string suffix = s.substr(i);
                vector<string> suffixBreaks = wordBreakHelper(suffix, wordDict, memo);
                // Append the prefix to each valid sentence from the suffix
                for (string str : suffixBreaks) {
                    result.push_back(prefix + (str.empty() ? "" : " ") + str);
                }
            }
        }
        
        // Store the result in the memoization map
        memo[s] = result;
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Convert wordDict to a set for faster lookup
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // Memoization map to store results of previously solved substrings
        unordered_map<string, vector<string>> memo;
        // Call the helper function
        return wordBreakHelper(s, wordSet, memo);
    }
};
