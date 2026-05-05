class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int sum=0;
        int left=0;
        for(int right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            if(sum>=target) ans=min(ans,right-left+1);
            while(left<right && sum>=target)
            {
                sum-=nums[left];
                left++;
                if(sum>=target) ans=min(ans,right-left+1);
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};