class Solution {
public:
    unordered_map<int,int> m;
    string recursion(string& s,int l,int r)
    {
        string temp;
        for(int i=l;i<=r;i++)
        {
            if(isalpha(s[i])) temp.push_back(s[i]);
            else
            {
                int j=i;
                while(isdigit(s[j])) j++; // now j points to '['
                int k=stoi(s.substr(i,j-i));
                string temp1=recursion(s,j+1,m[j]-1); //bcz m[j]-1 is the end of substr
                while(k>0)
                {
                    temp+=temp1;
                    k--;
                } // now temp1 is attached to temp k times lets proceed further in string s to 
                i=m[j]; // bcz loop increments by 1
            }
        }
        return temp;
    }
    string decodeString(string s) {
        // lets map pairs of open/close brackets
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='[' && s[i]!=']') continue;
            if(s[i]=='[') st.push({'[',i});
            else if(s[i]==']')
            {
                if(!st.empty() && st.top().first=='[')
                {
                    m.insert({st.top().second,i});
                    st.pop();
                }
            }
        }
        return recursion(s,0,s.size()-1);
    }
};