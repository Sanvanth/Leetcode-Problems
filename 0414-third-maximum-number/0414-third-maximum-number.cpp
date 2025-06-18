class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> arr;
        for(int num=0;num<nums.size();num++)
        {
            arr.insert(nums[num]);
            if(arr.size()>3)
            {
                arr.erase(arr.begin());
            }
        }
        if(arr.size()==3){
            return *arr.begin();
        }
        return *arr.rbegin();
    }
};