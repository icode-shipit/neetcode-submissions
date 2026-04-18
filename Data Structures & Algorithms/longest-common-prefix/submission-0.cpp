class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i=0;i<strs[0].size();i++)
        {
            char ref=strs[0][i];
            bool unmatch=false;
            for(int j=0;j<strs.size();j++)
            {
               if(strs[j][i]!=ref) 
               {
                 unmatch =true;
                 break;
               } 
            }
            if(unmatch)
            {
                return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};