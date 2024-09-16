class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;  // Add num to ones if it's not in twos
            twos = (twos ^ num) & ~ones;  // Add num to twos if it's not in ones
        }
        return ones;  // The number that appears exactly once will be in ones
    }
};
