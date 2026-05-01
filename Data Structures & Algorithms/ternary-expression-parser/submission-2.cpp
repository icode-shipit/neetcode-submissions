class Solution {
public:
    string recursion(string& s)
    {
        if(s.size()==1)
        {
            return string(1,s[0]);
        }
        int i=s.size()-1;
        while(s[i]!='?') i--; // i points '?'
        char seg= s[i-1]=='T' ? s[i+1] : s[i+3];
        s.erase(s.begin()+i-1,s.begin()+i+4);
        s.insert(i-1,string(1,seg));
        return recursion(s);
    } 
    string parseTernary(string expression) {
        return recursion(expression);
    }
};
