class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int sum=0;
        int ans=INT_MIN;
        for(int right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            while(right-left+1-sum>k && left<right)
            {
                sum-=nums[left];
                left++;
            }
            if(right-left+1-sum<=k) ans=max(ans,right-left+1);
        }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};