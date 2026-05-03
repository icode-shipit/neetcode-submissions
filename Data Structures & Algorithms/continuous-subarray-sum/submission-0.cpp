class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
           sum+=nums[i];
           int r= sum%k;
           if(r==0 && i>=1) return true;
           else if(m.contains(r) && i-m[r]>1) return true;
           if(!m.contains(r)) m[r]=i;
        }
        return false;
    }
};