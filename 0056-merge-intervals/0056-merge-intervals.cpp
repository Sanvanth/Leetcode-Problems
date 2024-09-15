#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        
        // Sort intervals by their start times
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        
        std::vector<std::vector<int>> merged;
        std::vector<int> current = intervals[0];
        
        for (const auto& interval : intervals) {
            if (interval[0] <= current[1]) {
                // There is overlap, merge the intervals
                current[1] = std::max(current[1], interval[1]);
            } else {
                // No overlap, push the current interval and update the current interval
                merged.push_back(current);
                current = interval;
            }
        }
        
        // Don't forget to add the last interval
        merged.push_back(current);
        
        return merged;
    }
};
