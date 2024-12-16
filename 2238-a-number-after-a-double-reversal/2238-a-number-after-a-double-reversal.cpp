class Solution {
public:
    bool isSameAfterReversals(int num) {
        
        string s=to_string(num);
        reverse(s.begin(),s.end());
        int rev1=stoi(s);
        s=to_string(rev1);
        reverse(s.begin(),s.end());
        int rev2=stoi(s);

        return rev2==num;

        
    }
};