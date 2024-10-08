class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());  // Convert wordDict to a set for faster lookup
        vector<bool> dp(s.size() + 1, false);  // DP array to store whether substring s[0:i] can be segmented
        dp[0] = true;  // Base case: empty string is always true

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                // If dp[j] is true and the substring s[j:i] is in the wordSet
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;  // No need to check further once dp[i] is true
                }
            }
        }

        return dp[s.size()];  // Whether the whole string can be segmented
    }
};
