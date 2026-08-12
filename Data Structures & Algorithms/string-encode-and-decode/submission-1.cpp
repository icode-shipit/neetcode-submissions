class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()!=0) ans.append(strs[i]);
            ans.append("\u2260");
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int l=0;
        int r=0;
        while(r<s.size())
        {
            if(r+3<=s.size() && s.compare(r,3,"\u2260")==0) //means end of string
            {
                if(r-l>0) ans.push_back(s.substr(l,r-l));
                else ans.push_back("");
                r+=3;
                l=r; 
            }
            else r++;
        }
        return ans;
    }
};
