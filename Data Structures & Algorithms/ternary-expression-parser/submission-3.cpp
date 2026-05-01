class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;
        for(int i=expression.size()-1;i>=0;i--)
        {
            if(expression[i]==':') continue;
            if(expression[i]=='?')
            {
                char tr= s.top(); s.pop();
                char fa= s.top(); s.pop();
                if(expression[i-1]=='T') s.push(tr);
                else s.push(fa);
                i--;
            }
            else s.push(expression[i]);
        }
        return string(1,s.top());
    }
};
