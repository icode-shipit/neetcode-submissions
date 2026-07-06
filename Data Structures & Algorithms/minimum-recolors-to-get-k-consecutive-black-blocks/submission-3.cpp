class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0;
        int cnt=0;
        int ans=blocks.size();
        for(int r=0;r<blocks.size();r++)
        {
            if(blocks[r]=='B') cnt++;
            if(r-l+1>k)
            {
                if(blocks[l]=='B') cnt--;
                l++;
            }
            if(r-l+1==k)
            {
                if(cnt==k) return 0;
                else ans=min(ans,k-cnt);
            }
        }
        return ans;
    }
};