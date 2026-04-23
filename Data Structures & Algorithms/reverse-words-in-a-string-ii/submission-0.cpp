class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
        {
            int j=i;
            while(j<s.size()-1 && s[j+1]!=' ')
            {
                j++;
            }
            // we have to reverse elements from [i,j]
            reverse(s.begin()+i,s.begin()+j+1);
            i=j+1;
        }
    }
};
