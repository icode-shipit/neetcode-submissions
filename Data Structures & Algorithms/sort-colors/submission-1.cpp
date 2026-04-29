class Solution {
public:
    void sortColors(vector<int>& nums) {
        int col[3]={0};
        for(int i=0;i<nums.size();i++)
        {
            col[nums[i]]++;
        }
        int i=0;
        for(int j=0;j<3;j++)
        {
            while(col[j]>0)
            {
                nums[i]=j;
                i++;
                col[j]--;
            }
        }
        return;
    }
};