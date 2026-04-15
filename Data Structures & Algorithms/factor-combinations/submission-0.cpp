class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void backtracking()
    {
        if(temp.size()>1)
        {
            ans.push_back(temp);
        }
        int prev=temp.back();
        temp.pop_back();
        for(int i= temp.empty()? 2:temp.back();i*i<=prev;i++)
        {
            if(prev%i==0)
            {
                temp.push_back(i);
                temp.push_back(prev/i);
                backtracking();
                temp.pop_back();
                temp.pop_back();
            }
        }
        temp.push_back(prev);
        return;
    }
    vector<vector<int>> getFactors(int n) {
        temp.push_back(n);
        backtracking();
        return ans;
    }
};
