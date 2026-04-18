class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int r=nums.size()-1;
        long long res=0;
        int MOD = 1e9+7;
        vector<long long> power(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            power[i] = (power[i-1] * 2) % MOD;
        }
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]+nums[r]>target && i<=r)
            {
                r--;
            }
            if(i<=r)
            {
               res = (res + power[r - i]) % MOD;
            }
        }
        return res;
    }
};