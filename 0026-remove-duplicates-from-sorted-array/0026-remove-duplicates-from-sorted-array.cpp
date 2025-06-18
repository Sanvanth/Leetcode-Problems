class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> arr;
        
        for(int num : nums){
            arr.insert(num);
        }
        auto val = arr.begin();
        for(int i=0;i<arr.size();i++){
            nums[i]=*val;
            val++;
        }
        return arr.size();
    }
};