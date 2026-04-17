class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        unordered_set<int> m;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='(' && s[i]!=')') continue;
            else
            {
                if(s[i]=='(')
                {
                   st.push({s[i],i});
                   m.insert(i);
                }
                else
                {
                    if(st.empty()) 
                    {
                        m.insert(i); // inserting an invalid positon
                        continue;
                    }
                    else
                    {
                        if(st.top().first=='(')
                        {
                            m.erase(st.top().second);
                            st.pop();
                            continue;
                        }
                    }
                }
            }
        }
        // now we have all the invalid pos in m
        string res;
        for(int i=0;i<s.size();i++)
        {
            if(m.contains(i)) continue;
            else
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};