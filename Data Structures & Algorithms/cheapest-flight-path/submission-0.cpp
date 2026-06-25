class Solution {
public:
    vector<vector<pair<int,int>>> v; //pair.first-> dst, pair.second-> price to reach that dst from src
    vector<vector<int>> dp;
    int helper(int src,int dst,int k)
    {
        if(src==dst) return 0;
        if(k==0 && src!=dst) return INT_MAX;
        if(dp[src][k]!=-1) return dp[src][k];
        long long ans=INT_MAX;
        for(int i=0;i<v[src].size();i++)
        {
           ans=min(ans,(long long)v[src][i].second+helper(v[src][i].first,dst,k-1));
        }
        return dp[src][k]=ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        v.resize(n);
        for(int i=0;i<flights.size();i++)
        {
            v[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        dp.resize(n,vector<int>(n+2,-1));
        int ans=helper(src,dst,k+1);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};