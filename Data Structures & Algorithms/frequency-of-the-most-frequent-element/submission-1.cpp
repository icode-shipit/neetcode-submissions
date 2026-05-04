class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int temp=k;
        int ans=1;
        for(int i=nums.size()-1;i>0;i--)
        {
            int frq=1;
            temp=k;
            int ref= nums[i];
            int j=i-1;
            while(j>=0 && temp>0)
            {
                temp-= ref-nums[j];
                if(temp>=0) frq++;
                j--;
            }
            ans=max(ans,frq);
        }
        return ans;
        
    }
};