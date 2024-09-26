class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize a vector with size (rowIndex + 1) to store the row
        vector<int> row(rowIndex + 1, 1);
        
        // Start calculating the elements of the row
        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                // Update the current element based on the previous one
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};
