class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> arr;
        
        for(int num : nums){
            arr.insert(num);
        }
        auto val = arr.begin();
        for(int i=0;i<nums.size();i++){
            if(i>arr.size()){
                nums[i]=0;
            }
            else{
                nums[i]=*val;
                val++;
            }
            
        }
        return arr.size();
    }
};