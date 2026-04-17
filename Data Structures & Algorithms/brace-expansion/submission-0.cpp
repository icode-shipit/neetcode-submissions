class Solution {
public:
    vector<string> ans;
    string temp;
    void backtracking(string& s,int l)
    {
        if(l==s.size())
        {
            ans.push_back(temp);
            return;
        }
        vector<char> possib;
        if(s[l]=='{')
        {
            l++;
            while(s[l]!='}')
            {
                if(s[l]==',') 
                {
                    l++;
                    continue;
                }
                possib.push_back(s[l]);
                l++;
            }
        }
        else possib.push_back(s[l]);
        for(int i=0;i<possib.size();i++)
        {
            temp.push_back(possib[i]);
            backtracking(s,l+1);
            temp.pop_back();
        }
        return;
    }
    vector<string> expand(string s) {
        backtracking(s,0);
        return ans;
    }
};
