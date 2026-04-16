class Solution {
public:
    unordered_map<char,string> m;
    unordered_set<string> used;
    bool backtracking(string& pattern, string& s,int p,int l)
    {
        if(p==pattern.size() && l==s.size()) return true;
        if(p<pattern.size() && l>=s.size()) return false;
        if(!m.contains(pattern[p]))
        {
           for(int i=l;i<(int)s.size();i++)
           {
              string curr_str= s.substr(l,i-l+1);
              if(used.contains(curr_str)) continue;
              m.insert({pattern[p],curr_str});
              used.insert(curr_str);
              if(backtracking(pattern,s,p+1,i+1))
              {
                return true;
              }
              m.erase(pattern[p]);
              used.erase(curr_str);
           }
           return false;
        }
           string& ref= m[pattern[p]];
           if(s.substr(l,ref.size())==ref) 
           {
              if(backtracking(pattern,s,p+1,l+ref.size())) return true;
           }
           return false;
    }
    bool wordPatternMatch(string pattern, string s) {
       return backtracking(pattern,s,0,0);
    }
};
