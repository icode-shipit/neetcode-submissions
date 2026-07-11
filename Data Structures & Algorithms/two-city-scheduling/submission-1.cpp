#include<cstring>;
class Solution {
public:
    int dp[101][51][51];
    int helper(vector<vector<int>>& costs,int p,int a,int b)
    {
        if(a>costs.size()/2 || b>costs.size()/2) return INT_MAX-1000;
        if(p==costs.size()) return 0; //that means n,n in each city
        if(dp[p][a][b]!=-1) return dp[p][a][b];
        int ans=costs[p][0]+helper(costs,p+1,a+1,b);
        ans=min(ans,costs[p][1]+helper(costs,p+1,a,b+1));
        return dp[p][a][b]=ans;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof(dp));
        return helper(costs,0,0,0);
    }
};