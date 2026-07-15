class Solution {
public:
    unordered_multiset<char> s;
    bool helper(int st,int e,string& s2)
    {
        unordered_multiset<char> temp=s;
        while(st<=e)
        {
            if(!temp.contains(s2[st])) return false;
            temp.erase(temp.find(s2[st]));
            st++;
        }
        if(temp.empty()) return true;
        return false;
    }
    bool checkInclusion(string s1, string s2) {
        for(int i=0;i<s1.size();i++)
        {
           s.insert(s1[i]);
        }
        for(int i=0;i<s2.size();i++)
        {
            if(s.contains(s2[i]))
            {
                if(helper(i,i+s1.size()-1,s2)) return true;
            }
        }
        return false;
    }
};
