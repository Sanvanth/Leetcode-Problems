class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        
        // Start from the end of both strings
        int i = a.size() - 1, j = b.size() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            // Add the current bit of 'a' if exists
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            
            // Add the current bit of 'b' if exists
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            
            // Append the current bit to result
            result += to_string(sum % 2);
            
            // Update the carry
            carry = sum / 2;
        }
        
        // Since the result is built in reverse order, reverse it at the end
        reverse(result.begin(), result.end());
        return result;
    }
};
