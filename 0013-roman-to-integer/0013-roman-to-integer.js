var romanToInt = function(s) {
    // Define a map to store Roman numeral values
    const romanMap = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };
    
    // Initialize the result variable
    let result = 0;
    
    // Loop through the string s
    for (let i = 0; i < s.length; i++) {
        // Check if the current numeral is less than the next numeral
        if (i < s.length - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
            // Subtract the current numeral from the result
            result -= romanMap[s[i]];
        } else {
            // Add the current numeral to the result
            result += romanMap[s[i]];
        }
    }
    
    return result;
};
