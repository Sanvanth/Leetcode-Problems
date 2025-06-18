
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.length() - 1;

        // Remove trailing spaces
        while (i >= 0 && s[i] == ' ') i--;

        // Count the last word's length
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};


