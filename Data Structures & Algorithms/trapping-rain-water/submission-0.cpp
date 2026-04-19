class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int ans=0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                int cap= leftmax-height[l];
                if(cap>0) ans+=cap;
                leftmax=max(leftmax,height[l]);
                l++;
            }
            else
            {
                int cap=rightmax-height[r];
                if(cap>0) ans+=cap;
                rightmax=max(rightmax,height[r]);
                r--;
            }
        }
        return ans;
    }
};