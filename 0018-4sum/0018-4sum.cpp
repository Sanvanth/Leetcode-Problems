#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Sort the array to facilitate two-pointer approach
        std::sort(nums.begin(), nums.end());
        
        // Iterate over the array with two loops to fix the first two elements
        for (int i = 0; i < n - 3; i++) {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // Avoid duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                // Use two-pointer approach to find the remaining two elements
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Move the left pointer and avoid duplicates
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Move the right pointer and avoid duplicates
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;  // We need a larger sum, so move left pointer right
                    } else {
                        right--;  // We need a smaller sum, so move right pointer left
                    }
                }
            }
        }
        
        return result;
    }
};

