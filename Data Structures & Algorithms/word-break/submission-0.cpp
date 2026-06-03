class Solution {
public:
    unordered_set<string> s1;
    int max_word_size=0;
    vector<int> dp;
    bool helper(string& s,int l)
    {
        if(l==s.size()) return 1;
        if(dp[l]==0 || dp[l]==1) return dp[l];
        string temp;
        for(int i=l;i<s.size();i++)
        {
            if(i-l+1>max_word_size) break;
            temp.push_back(s[i]);
            if(s1.contains(temp))
            {
                if(helper(s,i+1))
                {
                    return dp[l]=1;
                }
            }
        }
        return dp[l]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(),-1);
        for(int i=0;i<wordDict.size();i++)
        {
            max_word_size=max(max_word_size,(int)wordDict[i].size());
            s1.insert(wordDict[i]);
        }
        return helper(s,0);
    }
};