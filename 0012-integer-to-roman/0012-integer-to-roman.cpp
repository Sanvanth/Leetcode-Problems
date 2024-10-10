class Solution {
public:
    string intToRoman(int num) {
        // Define mappings of Roman symbols and their corresponding values.
        vector<pair<int, string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        // Result string to store the final Roman numeral.
        string result = "";
        
        // Iterate through the roman symbols from largest to smallest.
        for (const auto& [value, symbol] : roman) {
            // While the current num is larger than or equal to the current value,
            // subtract the value from num and append the corresponding symbol.
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};
