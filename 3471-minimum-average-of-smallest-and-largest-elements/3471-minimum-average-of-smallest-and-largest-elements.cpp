#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0.0;

        sort(nums.begin(), nums.end());

        vector<double> avgs;
        int l = 0, r = n - 1;

        while (l < r) {
            double a = (nums[l] + nums[r]) / 2.0;
            avgs.push_back(a);
            l++;
            r--;
        }
        if (avgs.empty())
            return 0.0;
        return *min_element(avgs.begin(), avgs.end());
    }
};