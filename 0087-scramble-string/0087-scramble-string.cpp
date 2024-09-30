#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Memoization table
    unordered_map<string, bool> memo;

    // Helper function to check scramble recursively
    bool isScrambleHelper(const string& s1, const string& s2) {
        // If the strings are identical, they are trivially scrambled versions
        if (s1 == s2) return true;

        // Check if the problem has already been solved
        string key = s1 + "_" + s2;
        if (memo.find(key) != memo.end()) return memo[key];

        int n = s1.size();

        // If the sorted characters of s1 and s2 don't match, return false
        string sorted_s1 = s1;
        string sorted_s2 = s2;
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());
        if (sorted_s1 != sorted_s2) {
            memo[key] = false;
            return false;
        }

        // Try splitting the string in every possible way
        for (int i = 1; i < n; ++i) {
            // Case 1: No swap
            if (isScrambleHelper(s1.substr(0, i), s2.substr(0, i)) && 
                isScrambleHelper(s1.substr(i), s2.substr(i))) {
                memo[key] = true;
                return true;
            }
            // Case 2: Swap
            if (isScrambleHelper(s1.substr(0, i), s2.substr(n - i)) && 
                isScrambleHelper(s1.substr(i), s2.substr(0, n - i))) {
                memo[key] = true;
                return true;
            }
        }

        // If none of the above conditions are met, s2 is not a scrambled string of s1
        memo[key] = false;
        return false;
    }

    // Main function to check if s2 is a scrambled string of s1
    bool isScramble(string s1, string s2) {
        // If lengths differ, they can't be scrambled strings
        if (s1.length() != s2.length()) return false;

        // Use the helper function for the recursive checking
        return isScrambleHelper(s1, s2);
    }
};
