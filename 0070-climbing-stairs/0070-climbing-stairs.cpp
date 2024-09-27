class Solution {
public:
    int climbStairs(int n) {
        int pre2 = 1;
        int pre1 = 1;
       int i=1;
       while( i < n){
            int next = pre1 +pre2;
            pre2=pre1;
            pre1 = next;
            i++;
        }
        return pre1;
    }
};