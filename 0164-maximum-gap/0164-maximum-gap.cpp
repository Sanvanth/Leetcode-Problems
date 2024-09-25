class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        
        int n = nums.size();
        int bucketSize = max(1, (maxVal - minVal) / (n - 1)); // Minimum bucket size is 1
        int bucketCount = (maxVal - minVal) / bucketSize + 1; // Number of buckets
        
        vector<pair<int, int>> buckets(bucketCount, {-1, -1}); // Initialize buckets to store (min, max)
        
        // Place each number in the appropriate bucket
        for (int num : nums) {
            int bucketIndex = (num - minVal) / bucketSize;
            if (buckets[bucketIndex].first == -1) {
                buckets[bucketIndex].first = num;
                buckets[bucketIndex].second = num;
            } else {
                buckets[bucketIndex].first = min(buckets[bucketIndex].first, num);
                buckets[bucketIndex].second = max(buckets[bucketIndex].second, num);
            }
        }
        
        // Calculate the maximum gap
        int prevMax = minVal; // Start with the minVal
        int maxGap = 0;
        
        for (const auto& bucket : buckets) {
            if (bucket.first == -1) continue; // Empty bucket
            maxGap = max(maxGap, bucket.first - prevMax); // Update the maximum gap
            prevMax = bucket.second;
        }
        
        return maxGap;
    }
};
