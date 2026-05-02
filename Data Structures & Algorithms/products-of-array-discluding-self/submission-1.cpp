class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zerocnt=0;
        int total_prod=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0) total_prod*=nums[i];
            else zerocnt++;
        }
        vector<int> ans(nums.size(),0);
        if(zerocnt>1) return ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) ans[i]=total_prod;
            else 
            {
                if(zerocnt==0) ans[i]=total_prod/nums[i];
                else ans[i]=0; 
            }
        }
        return ans;
    }
};