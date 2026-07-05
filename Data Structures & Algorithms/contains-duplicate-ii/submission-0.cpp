class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0;
        unordered_map<int,int> m;
        for(int j=0;j<nums.size();j++)
        {
            if(j-i>k) break;
            m[nums[j]]++;
            if(m[nums[j]]>1) return true;
        }
        int j=i+k;
        while(j+1<nums.size())
        {
            m[nums[i]]--;
            m[nums[j+1]]++;
            if(m[nums[j+1]]>1) return true;
            i++;
            j++;
        }
        return false;
    }
};