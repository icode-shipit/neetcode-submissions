class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            if(r-l<=k)
            {
                m[nums[r]]++;
                if(m[nums[r]]>1) return true;
            }
            else
            {
                m[nums[r]]++;
                m[nums[l]]--;
                if(m[nums[r]]>1) return true;
                l++;
            }
        }
        return false;
    }
};