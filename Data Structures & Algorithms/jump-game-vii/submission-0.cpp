class Solution {
public:
    vector<int> dp;
    bool helper(string& s,int p,int minJump, int maxJump)
    {
        if(p==s.size()-1) return true; 
        int start=p+minJump;
        int end= min(p+maxJump,(int)s.size() - 1);
        if(start>=s.size()) return false;
        if(dp[p]!=-1) return dp[p];
        for(int i=start;i<=end;i++)
        {
            if(s[i]!='0') continue;
            if(helper(s,i,minJump,maxJump)) return true;
        }
        return dp[p]=false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        dp.assign(s.size()+1,-1);
        return helper(s,0,minJump,maxJump);
    }
};