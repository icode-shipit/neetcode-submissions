class Solution {
public:
    vector<vector<int>> dp;
    bool helper(string& s1, string &s2, string &s3, int p1, int p2, int p3)
    {
        if(p3==s3.size() && p1==s1.size() && p2==s2.size()) return true;
        if(dp[p1][p2]!=-1) return dp[p1][p2];
        bool cond1=false;
        bool cond2=false;
        if(p1<s1.size() && s1[p1]==s3[p3])
        {
            cond1= helper(s1,s2,s3,p1+1,p2,p3+1);
        }
        if(!cond1 && p2<s2.size() && s2[p2]==s3[p3])
        {
            cond2= helper(s1,s2,s3,p1,p2+1,p3+1);
        }
        return dp[p1][p2]=cond1 || cond2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!= s2.size()+s1.size()) return false;
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(s1,s2,s3,0,0,0);
    }
};