class Solution {
public:
    vector<string> temp;
    vector<vector<string>> ans;
    bool palindrome(string& s)
    {
        int l=0;
        int r=s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void backtracking(string s)
    {
        if(s.empty())
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<s.size();i++)
        {
            string s1=s.substr(0,i+1);
            if(palindrome(s1)==true)
            {
                temp.push_back(s1);
                backtracking(s.substr(i+1,s.size()-i-1));
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s);
        return ans;
    }
};
