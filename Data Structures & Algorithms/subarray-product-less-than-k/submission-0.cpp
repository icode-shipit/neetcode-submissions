class Solution {
public:
    int findallsubarratprodmostk(vector<int>& nums,int k)
    {
        int ans=0;
        int prod=1;
        int left=0;
        for(int right=0;right<nums.size();right++)
        {
            prod*=nums[right];
            while(prod>k && left<right)
            {
                prod/=nums[left];
                left++;
            }
            if(prod<=k) ans+=right-left+1;
        }
        return ans;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        return findallsubarratprodmostk(nums,k-1);
    }
};