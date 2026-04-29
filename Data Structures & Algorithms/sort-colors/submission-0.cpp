class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int i=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            while(it->second>0)
            {
                nums[i]=it->first;
                i++;
                it->second--;
            }
        }
        return;
    }
};