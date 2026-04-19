class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        if(nums.size()==1)
        {
            return nums[0];
        }
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(mid+1<nums.size() && nums[mid]==nums[mid+1]) 
            {
                int rightsize= (r-mid+1)-2;
                int leftsize= (mid-l+1)-1;
                if(rightsize%2!=0)
                {
                   l=mid+2;
                }
                else
                {
                   r=mid-1;
                }
            }
            else if(mid-1>=0 && nums[mid]==nums[mid-1])
            {
                int rightsize= (r-mid+1)-1;
                int leftsize= (mid-l+1)-2;;
                if(rightsize%2!=0)
                {
                   l=mid+1;
                }
                else
                {
                   r=mid-2;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return 0;
    }
};