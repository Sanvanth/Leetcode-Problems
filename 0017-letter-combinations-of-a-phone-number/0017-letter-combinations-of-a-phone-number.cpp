#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Mapping of digits to letters
    const vector<string> digitToLetters = {
        "",     // 0 (no mapping)
        "",     // 1 (no mapping)
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    
    // Backtracking function to generate combinations
    void backtrack(string& digits, int index, string& current, vector<string>& result) {
        // Base case: If we've processed all digits, add the current combination to the result
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        // Get the digit at the current index
        char digit = digits[index];
        // Get the corresponding letters for this digit
        string letters = digitToLetters[digit - '0']; // Convert char to int
        
        // Try each letter and continue to backtrack
        for (char letter : letters) {
            current.push_back(letter); // Choose
            backtrack(digits, index + 1, current, result); // Explore
            current.pop_back(); // Un-choose (backtrack)
        }
    }

    // Main function
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result; // If input is empty, return empty result

        string current;
        backtrack(digits, 0, current, result); // Start backtracking
        return result;
    }
};
