class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(int n,int p,int k)
    {
        if(temp.size()==k)
        {
           ans.push_back(temp);
           return;
        }
        if(p==n+1) return;
        helper(n,p+1,k); //ignoring the current num
        if(temp.size()+1<=k)
        {
            temp.push_back(p);
            helper(n,p+1,k);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        helper(n,1,k);
        return ans;
    }
};