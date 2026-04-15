class Solution {
public:
    bool backtracking(int k,int p,vector<int>& nums,int set_sum,int val)
    {
        if(k==0)
        {
            return true;
        }
        if(set_sum==val)
        {
            if(backtracking(k-1,0,nums,0,val))
            {
                return true;
            }
        }
        for(int i=p;i<nums.size();i++)
        {
            if(nums[i]==-1) continue;
            if(set_sum+nums[i]<=val)
            {
                int temp=nums[i];
                nums[i]=-1;
                if(backtracking(k,i+1,nums,set_sum+temp,val))
                {
                    return true;
                }
                nums[i]=temp;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)
        {
            return false;
        }
        sort(nums.rbegin(),nums.rend());
        return backtracking(k,0,nums,0,sum/k);
    }
};