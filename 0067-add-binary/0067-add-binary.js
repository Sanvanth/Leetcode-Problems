var addBinary = function(a, b) {
    let i = a.length - 1;
    let j = b.length - 1;
    let carry = 0;
    let result = '';
    
    // Process both strings from the end towards the beginning
    while (i >= 0 || j >= 0 || carry) {
        let sum = carry;
        
        // Add the corresponding bit of a if i is valid
        if (i >= 0) {
            sum += a[i] - '0'; // Convert character to integer
            i--;
        }
        
        // Add the corresponding bit of b if j is valid
        if (j >= 0) {
            sum += b[j] - '0'; // Convert character to integer
            j--;
        }
        
        // Add the sum's last bit to the result and update carry
        result = (sum % 2) + result;
        carry = Math.floor(sum / 2);
    }
    
    return result;
};
