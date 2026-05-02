class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(); 
        vector<int> prefixsum(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            prefixsum[i]=sum;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i==0 && prefixsum[j]==k) ans++;
                else if( i>0 && prefixsum[j]-prefixsum[i-1]==k) ans++;
            }
        }
        return ans;
    }
};