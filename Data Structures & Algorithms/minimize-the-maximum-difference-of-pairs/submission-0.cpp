class Solution {
public:
    bool is_valid(vector<int>& nums,int target,int m)
    {
        int ans=0;
        int p=0;
        while(p<nums.size()-1)
        {
            if(abs(nums[p]-nums[p+1])<=target) 
            {
                ans++;
                p+=2;
            }
            else p++;
            if(ans==m) return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        sort(nums.begin(),nums.end());
        int l=0;
        int r=abs(nums[0]-nums.back());
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(is_valid(nums,mid,p))
            {
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};