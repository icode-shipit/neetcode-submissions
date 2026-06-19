#include <cstring> // <-- Add this to fix the memset compilation error
#include <vector>
class Solution {
public:
    int dp1[500][500]; // p1,p2 stores alice stones
    int dp2[500][500]; // p1,p2 stores bob stones
    vector<int> helper(vector<int>& piles,bool alice_turn,int p1,int p2) //alice,bob
    {
        if(p1>p2) return {0,0};
        if(dp1[p1][p2]!=-1) return {dp1[p1][p2],dp2[p1][p2]};
        if(alice_turn)
        {
            vector<int> temp1= helper(piles,0,p1+1,p2); //using piles[p1]
            vector<int> temp2= helper(piles,0,p1,p2-1); //using piles[p2];
            vector<int> ans= (temp1[0]+piles[p1]>temp2[0]+piles[p2]) ?  vector<int>{temp1[0]+piles[p1],temp1[1]} :  vector<int>{temp2[0]+piles[p2],temp2[1]};
            dp1[p1][p2]=ans[0]; dp2[p1][p2]=ans[1];
            return ans;
        }
        vector<int> temp1= helper(piles,1,p1+1,p2); //using piles[p1]
        vector<int> temp2= helper(piles,1,p1,p2-1); //using piles[p2];
        vector<int>  ans= (temp1[1]+piles[p1]>temp2[1]+piles[p2]) ?  vector<int> {temp1[0],temp1[1]+piles[p1]} :  vector<int> {temp2[0],temp2[1]+piles[p2]};
        dp1[p1][p2]=ans[0]; dp2[p1][p2]=ans[1];
        return ans;
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp2,-1,sizeof(dp2));
        memset(dp1,-1,sizeof(dp1));
        vector<int> ans=helper(piles,1,0,piles.size()-1);
        return ans[0]>ans[1] ? true : false;
    }
};