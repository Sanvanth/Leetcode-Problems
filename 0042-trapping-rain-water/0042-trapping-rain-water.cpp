class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int n = height.size();
        int left = 0, right = n - 1; // Two pointers
        int leftMax = 0, rightMax = 0; // To store the max heights
        int waterTrapped = 0;
        
        while (left < right) {
            // We work on the smaller side because the amount of trapped water
            // depends on the shorter height between leftMax and rightMax.
            if (height[left] < height[right]) {
                // Update leftMax and calculate water trapped on the left side
                if (height[left] >= leftMax) {
                    leftMax = height[left]; // Update leftMax
                } else {
                    waterTrapped += leftMax - height[left]; // Water trapped
                }
                left++; // Move the left pointer
            } else {
                // Update rightMax and calculate water trapped on the right side
                if (height[right] >= rightMax) {
                    rightMax = height[right]; // Update rightMax
                } else {
                    waterTrapped += rightMax - height[right]; // Water trapped
                }
                right--; // Move the right pointer
            }
        }
        
        return waterTrapped;
    }
};
