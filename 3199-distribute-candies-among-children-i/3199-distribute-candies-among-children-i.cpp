class Solution {
public:
    int distributeCandies(int n, int limit) {
        int minFirst = max(0, n - 2 * limit);  // Minimum for first child
        int maxFirst = min(n, limit);          // Maximum for first child
        int ways = 0;

        for (int i = minFirst; i <= maxFirst; i++) {
            int N = n - i;  // Remaining candies

            int minCh2 = max(0, N - limit);    // Second child's minimum
            int maxCh2 = min(N, limit);        // Second child's maximum

            ways += maxCh2 - minCh2 + 1;       // Valid (second, third) combos
        }

        return ways;
    }
};