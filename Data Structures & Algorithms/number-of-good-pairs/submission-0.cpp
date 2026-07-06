class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int ans=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            int temp=it->second;
            ans+=(temp-1)*temp/2;
        }
        return ans;
    }
};