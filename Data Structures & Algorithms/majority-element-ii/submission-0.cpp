class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>nums.size()/3) 
            {
                if(ans.empty() || ans.back()!=nums[i]) ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};