#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        // Step 1: Trim leading and trailing spaces
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;
        
        // Step 2: Split words and ignore multiple spaces
        std::vector<std::string> words;
        std::string word;
        while (left <= right) {
            char c = s[left];
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            left++;
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        // Step 3: Reverse the order of words
        std::reverse(words.begin(), words.end());
        
        // Step 4: Join the words with a single space
        std::string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        
        return result;
    }
};
