class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int l=0; //represent neg
        int r=0; // respresent pos
        while(l<nums.size() && r<nums.size())
        {
            while(nums[l]>0)
            {
                l++;
            }
            while(nums[r]<0) 
            {
                r++;
            }
            ans.push_back(nums[r]);
            ans.push_back(nums[l]);
            l++;
            r++;
        }
        return ans;
    }
};