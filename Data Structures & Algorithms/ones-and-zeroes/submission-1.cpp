#include <cstring>
class Solution {
public:
    int dp[101][101][601];
    int helper(vector<pair<int,int>> &v,int p,int f,int s,int m,int n)
    {
        if(p==v.size()) return 0;
        if(dp[f][s][p]!=-1) return dp[f][s][p];
        int ans1=0;
        if(f+v[p].first<=n && s+v[p].second<=m)
        {
           ans1= 1+helper(v,p+1,f+v[p].first,s+v[p].second,m,n);
        }
        int ans2=helper(v,p+1,f,s,m,n);
        return dp[f][s][p]=max(ans1,ans2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> v(strs.size()); //first->1,second->0
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='1') v[i].first++;
                else if(strs[i][j]=='0') v[i].second++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return helper(v,0,0,0,m,n); //curr->first --- 1, curr->second ----0
    }
};