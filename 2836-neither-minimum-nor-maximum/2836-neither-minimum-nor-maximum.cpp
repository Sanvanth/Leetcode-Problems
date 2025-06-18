class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        set<int> arr;
        for(int num=0;(num<nums.size());num++)
        {
            arr.insert(nums[num]);
        }
        if(arr.size()<=2){
            return -1;
        }
        auto val = arr.begin();
        val++;
        return *val;
    }
};