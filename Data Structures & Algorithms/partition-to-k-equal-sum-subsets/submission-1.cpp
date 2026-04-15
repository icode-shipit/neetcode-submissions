class Solution {
public:
    bool backtracking(int val,int k,vector<int>& v,int p,vector<int>& nums)
    {
        if(p==nums.size())
        {
            return true;
        }
        int fail_case=-1;
        for(int i=0;i<v.size();i++)
        {
            if(fail_case==v[i]) continue;
            if(v[i]+nums[p]<=val)
            {
                v[i]+=nums[p];
                if(backtracking(val,k,v,p+1,nums))
                {
                    return true;
                }
                v[i]-=nums[p];
                fail_case=v[i];
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
        vector<int> v(k);
        return backtracking(sum/k,k,v,0,nums);
    }
};