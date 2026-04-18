class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while(x!=0)
        {
            int curr_val=x%10;
            x=x/10;
            if(rev>(INT_MAX)/10) return 0;
            if(rev<(INT_MIN)/10) return 0;
            rev=rev*10+curr_val;
        }
        return rev;
    }
};
