class Solution {
public:
    int appendCharacters(string s, string t) {
        int l=0;
        int r=0;
        int count=0;
        while(l<s.size() && r<t.size())
        {
            bool found=false;
            while(!found && l<s.size())
            {
                if(s[l]==t[r]) 
                {
                    count++;
                    found=true;
                }
                l++;
            }
            r++;
        }
        return t.size()-count;
    }
};