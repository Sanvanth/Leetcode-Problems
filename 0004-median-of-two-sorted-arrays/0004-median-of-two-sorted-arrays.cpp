class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure that nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            // Check if we have a valid partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total number of elements is even
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else { // If total number of elements is odd
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Move partition1 to the left
                high = partition1 - 1;
            } else {
                // Move partition1 to the right
                low = partition1 + 1;
            }
        }
        
        // If input arrays are not sorted correctly
        throw invalid_argument("Input arrays are not sorted");
    }
};
