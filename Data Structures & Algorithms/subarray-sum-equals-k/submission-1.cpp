class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size(); 
        vector<int> prefixsum(n);
        int sum=0;
        int ans=0;
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            prefixsum[i]=sum;
            ans+=m[prefixsum[i]-k];
            m[prefixsum[i]]++;
        }
        return ans; 
    }
};