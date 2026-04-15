class Solution {
public:
    vector<string> ans;
    string temp;
    void backtracking(int l,string& s,int dotcnt)
    {
        if(dotcnt==0 && s.size()-l>3)
        {
            return;
        }
        else if(dotcnt==0 && s.size()-l<=3)
        {
            if(s.size()-l>1)
            {
                if(s[l]=='0')
                {
                    return;
                }
            }
            if(l==s.size())
            {
                return;
            }
            if(stoi(s.substr(l,s.size()-l))<=255)
            {
               temp+=s.substr(l,s.size()-l);
               ans.push_back(temp);
            }
            return;
        }
        if(l>=s.size()-1 || s.size()<4 || s.size()>12)
        {
            return;
        }
        for(int r=l;r<s.size() && r-l+1<=3;r++)
        {
            if(r-l+1>2)
            {
                if(stoi(s.substr(l,r-l+1))>255)
                { 
                   continue;
                }
            }
            int org_len=temp.size();
            if(s[l]=='0' && r-l+1>1)
            {
               continue;
            }
            temp+=s.substr(l,r-l+1)+".";
            backtracking(r+1,s,dotcnt-1);
            temp.erase(org_len,temp.size()-org_len);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(0,s,3);
        return ans;
    }
};