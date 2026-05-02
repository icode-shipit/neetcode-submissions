class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftprod(nums.size());
        vector<int> rightprod(nums.size());
        int prod=1;
        for(int i=0;i<nums.size();i++)
        {
            prod*=nums[i];
            leftprod[i]=prod;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            prod*=nums[i];
            rightprod[i]=prod;
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(i==0) ans[i]=rightprod[i+1];
            else if(i==nums.size()-1) ans[i]=leftprod[i-1];
            else ans[i]=leftprod[i-1]*rightprod[i+1];
        }
        return ans;
    }
};