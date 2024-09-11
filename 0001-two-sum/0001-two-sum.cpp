#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;  // To store the number and its index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // Find the complement
            if (num_map.find(complement) != num_map.end()) {
                // If the complement exists, return the indices
                return {num_map[complement], i};
            }
            // Store the number and its index in the map
            num_map[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};